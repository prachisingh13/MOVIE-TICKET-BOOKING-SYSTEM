#include "Ticket.h"
#include <iomanip>
#include <iostream>

void Ticket::printTicket(const Booking& booking) {
    std::cout << "\n========== MOVIE TICKET ==========\n";
    std::cout << "Booking ID : " << booking.getBookingId() << "\n";
    std::cout << "Customer   : " << booking.getCustomer()->getName() << "\n";
    std::cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
    std::cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << "\n";
    std::cout << "Time       : " << booking.getShow()->getStartTime() << "\n";
    std::cout << "Seats      : ";

    bool first = true;
    for (const auto* seat : booking.getSeats()) {
        if (!first) std::cout << ", ";
        std::cout << seat->seat->getSeatNo();
        first = false;
    }

    std::cout << "\nTotal      : Rs. "
              << std::fixed << std::setprecision(2)
              << booking.getTotalAmount() << "\n";
    std::cout << "Status     : " << bookingStatusToString(booking.getStatus()) << "\n";
    std::cout << "==================================\n";
}
