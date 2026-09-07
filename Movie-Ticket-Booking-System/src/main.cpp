#include "Booking.h"
#include "Cinema.h"
#include "Customer.h"
#include "Movie.h"
#include "Payment.h"
#include "Price.h"
#include "Show.h"
#include "Ticket.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

namespace {

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(const std::string& prompt, int min, int max) {
    while (true) {
        std::cout << prompt;
        int value;
        if (std::cin >> value && value >= min && value <= max) {
            return value;
        }
        std::cout << "Invalid input. Please enter a value from "
                  << min << " to " << max << ".\n";
        clearInput();
    }
}

void listMovies(const std::vector<Movie>& movies) {
    std::cout << "\n========== MOVIES CURRENTLY PLAYING ==========\n";
    for (std::size_t i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i].getTitle()
                  << " | " << movies[i].getLanguage()
                  << " | " << movies[i].getDuration() << " min\n";
    }
}

void listShows(const std::vector<Show>& shows, int movieIndex) {
    std::cout << "\n========== SHOWS ==========\n";
    int number = 1;
    for (const auto& show : shows) {
        if (show.getMovie()->getTitle() ==
            (movieIndex == 0 ? "Harry Potter : The Prisoner of Azkaban" :
             movieIndex == 1 ? "12th Fail" : "Mission Mangal")) {
            std::cout << number++ << ". Screen "
                      << show.getScreen()->getScreenNumber()
                      << " | " << show.getStartTime() << "\n";
        }
    }
}

std::vector<Show*> getMovieShows(std::vector<Show>& shows, Movie* movie) {
    std::vector<Show*> result;
    for (auto& show : shows) {
        if (show.getMovie() == movie) result.push_back(&show);
    }
    return result;
}

void displayMovieInfo(const std::vector<Movie>& movies) {
    listMovies(movies);
}

void runBooking(std::vector<Show>& shows, const std::vector<Movie>& movies,
                int& nextBookingId) {
    listMovies(movies);
    int movieChoice = readInt("Select movie (1-3): ", 1, 3) - 1;

    auto movieShows = getMovieShows(shows,
                                    const_cast<Movie*>(&movies[movieChoice]));

    std::cout << "\nShows for " << movies[movieChoice].getTitle() << ":\n";
    for (std::size_t i = 0; i < movieShows.size(); ++i) {
        std::cout << i + 1 << ". Screen "
                  << movieShows[i]->getScreen()->getScreenNumber()
                  << " | " << movieShows[i]->getStartTime() << "\n";
    }

    int showChoice = readInt(
        "Select show (1-" + std::to_string(movieShows.size()) + "): ",
        1, static_cast<int>(movieShows.size())) - 1;

    Show* selectedShow = movieShows[showChoice];
    selectedShow->displaySeats();

    std::cout << "\nEnter seat numbers separated by spaces, ending with 0.\n";
    std::vector<ShowSeat*> selectedSeats;

    while (true) {
        int seatNo = readInt("Seat number (1-15, 0 to finish): ", 0, 15);
        if (seatNo == 0) break;

        ShowSeat* seat = selectedShow->findShowSeat(seatNo);
        if (!seat) {
            std::cout << "Invalid seat number.\n";
            continue;
        }
        if (!seat->isAvailable()) {
            std::cout << "Seat " << seatNo << " is already booked.\n";
            continue;
        }

        bool duplicate = false;
        for (const auto* existing : selectedSeats) {
            if (existing->seat->getSeatNo() == seatNo) duplicate = true;
        }

        if (duplicate) {
            std::cout << "Seat already selected.\n";
            continue;
        }

        selectedSeats.push_back(seat);
    }

    if (selectedSeats.empty()) {
        std::cout << "No seats selected. Booking cancelled.\n";
        return;
    }

    double total = Price::calculateTotal(selectedSeats);
    std::cout << "\nTotal amount: Rs. " << std::fixed
              << std::setprecision(2) << total << "\n";

    std::string name, phone;
    std::cout << "Customer name: ";
    std::cin >> std::ws;
    std::getline(std::cin, name);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);

    Customer customer(name, phone);
    Booking booking(nextBookingId++, &customer, selectedShow, selectedSeats, total);

    std::cout << "\nPayment Method\n";
    std::cout << "1. UPI\n2. Card\n3. Cash\n";
    int paymentChoice = readInt("Choose payment method: ", 1, 3);

    std::unique_ptr<Payment> payment;
    if (paymentChoice == 1) payment = std::make_unique<UPI>();
    else if (paymentChoice == 2) payment = std::make_unique<Card>();
    else payment = std::make_unique<Cash>();

    if (payment->pay(total)) {
        if (booking.confirm()) {
            std::cout << "\nBooking confirmed successfully!\n";
            Ticket::printTicket(booking);

            std::cout << "\nDo you want to cancel this booking? (1=Yes, 0=No): ";
            int cancel = readInt("", 0, 1);
            if (cancel == 1) {
                booking.cancel();
                std::cout << "Booking cancelled. Seats are available again.\n";
            }
        }
    } else {
        booking.fail();
        std::cout << "Payment failed. Seats released. Booking failed.\n";
    }
}

} // namespace

int main() {
    std::cout << "==============================================\n";
    std::cout << "     MOVIE TICKET BOOKING SYSTEM\n";
    std::cout << "==============================================\n";

    std::vector<Movie> movies = {
        {"Harry Potter : The Prisoner of Azkaban", "English", 142},
        {"12th Fail", "Hindi", 147},
        {"Mission Mangal", "Hindi", 127}
    };

    Cinema cinema("Single Screen Cinema");

    for (int screenNo = 1; screenNo <= 3; ++screenNo) {
        Screen screen(screenNo);

        for (int seatNo = 1; seatNo <= 15; ++seatNo) {
            SeatType type;
            if (seatNo <= 5) type = SeatType::Silver;
            else if (seatNo <= 10) type = SeatType::Gold;
            else type = SeatType::Platinum;

            screen.addSeat(Seat(seatNo, type));
        }

        cinema.addScreen(screen);
    }

    std::vector<Show> shows;
    const std::vector<std::vector<std::string>> timings = {
        {"08:00 - 10:00", "12:00 - 14:00", "21:00 - 23:00"},
        {"11:00 - 14:30", "15:00 - 18:30", "18:30 - 21:30"},
        {"08:00 - 10:30", "10:00 - 12:30", "16:00 - 18:30"}
    };

    for (int movieIndex = 0; movieIndex < 3; ++movieIndex) {
        for (int screenIndex = 0; screenIndex < 3; ++screenIndex) {
            shows.emplace_back(
                &movies[movieIndex],
                cinema.getScreen(screenIndex + 1),
                timings[movieIndex][screenIndex]
            );
        }
    }

    // Demonstration of initially booked seats.
    // This mirrors the assignment's requirement analysis examples.
    shows[0].findShowSeat(3)->book();
    shows[1].findShowSeat(2)->book();
    shows[2].findShowSeat(1)->book();

    int nextBookingId = 1001;

    while (true) {
        std::cout << "\n========== MAIN MENU ==========\n";
        std::cout << "1. List Movies\n";
        std::cout << "2. View Shows\n";
        std::cout << "3. View Seat Layout\n";
        std::cout << "4. Book Tickets\n";
        std::cout << "5. Exit\n";

        int choice = readInt("Enter choice: ", 1, 5);

        if (choice == 1) {
            displayMovieInfo(movies);
        } else if (choice == 2) {
            listMovies(movies);
            int movieChoice = readInt("Select movie (1-3): ", 1, 3) - 1;
            listShows(shows, movieChoice);
        } else if (choice == 3) {
            listMovies(movies);
            int movieChoice = readInt("Select movie (1-3): ", 1, 3) - 1;
            auto movieShows = getMovieShows(
                shows, const_cast<Movie*>(&movies[movieChoice])
            );
            for (std::size_t i = 0; i < movieShows.size(); ++i) {
                std::cout << i + 1 << ". Screen "
                          << movieShows[i]->getScreen()->getScreenNumber()
                          << " | " << movieShows[i]->getStartTime() << "\n";
            }
            int showChoice = readInt(
                "Select show: ", 1, static_cast<int>(movieShows.size())
            ) - 1;
            movieShows[showChoice]->displaySeats();
        } else if (choice == 4) {
            runBooking(shows, movies, nextBookingId);
        } else {
            std::cout << "\nThank you for using the Movie Ticket Booking System!\n";
            break;
        }
    }

    return 0;
}
