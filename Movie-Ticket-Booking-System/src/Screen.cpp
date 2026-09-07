#include "Screen.h"

Screen::Screen(int screenNo) : screenNo(screenNo) {}

void Screen::addSeat(const Seat& seat) {
    seats.push_back(seat);
}

int Screen::getScreenNumber() const {
    return screenNo;
}

const std::vector<Seat>& Screen::getSeats() const {
    return seats;
}

Seat* Screen::findSeat(int seatNo) {
    for (auto& seat : seats) {
        if (seat.getSeatNo() == seatNo) return &seat;
    }
    return nullptr;
}
