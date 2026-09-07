#include "Seat.h"

Seat::Seat(int seatNo, SeatType type) : seatNo(seatNo), type(type) {}

int Seat::getSeatNo() const { return seatNo; }

SeatType Seat::getType() const { return type; }

double Seat::getPrice() const {
    switch (type) {
        case SeatType::Silver: return 180.0;
        case SeatType::Gold: return 300.0;
        case SeatType::Platinum: return 450.0;
    }
    return 0.0;
}

std::string Seat::getTypeName() const {
    switch (type) {
        case SeatType::Silver: return "Silver";
        case SeatType::Gold: return "Gold";
        case SeatType::Platinum: return "Platinum";
    }
    return "Unknown";
}
