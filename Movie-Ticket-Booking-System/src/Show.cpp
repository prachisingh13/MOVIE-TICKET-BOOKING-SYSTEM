#include "Show.h"
#include <iostream>

bool ShowSeat::isAvailable() const {
    return status == SeatStatus::Available;
}

void ShowSeat::book() {
    status = SeatStatus::Booked;
}

void ShowSeat::release() {
    status = SeatStatus::Available;
}

Show::Show(Movie* movie, Screen* screen, const std::string& startTime)
    : movie(movie), screen(screen), startTime(startTime) {
    for (const auto& seat : screen->getSeats()) {
        showSeats.push_back({const_cast<Seat*>(&seat), SeatStatus::Available});
    }
}

Movie* Show::getMovie() const { return movie; }
Screen* Show::getScreen() const { return screen; }
std::string Show::getStartTime() const { return startTime; }
std::vector<ShowSeat>& Show::getShowSeats() { return showSeats; }

ShowSeat* Show::findShowSeat(int seatNo) {
    for (auto& showSeat : showSeats) {
        if (showSeat.seat->getSeatNo() == seatNo) return &showSeat;
    }
    return nullptr;
}

void Show::displaySeats() const {
    std::cout << "\nSeat Layout - Screen " << screen->getScreenNumber() << "\n";
    std::cout << "---------------------------------------------\n";
    for (const auto& showSeat : showSeats) {
        std::cout << "Seat " << showSeat.seat->getSeatNo()
                  << " [" << showSeat.seat->getTypeName() << "] : "
                  << seatStatusToString(showSeat.status) << "\n";
    }
}
