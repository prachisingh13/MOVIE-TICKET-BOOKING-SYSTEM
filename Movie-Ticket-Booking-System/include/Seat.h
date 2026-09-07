#ifndef SEAT_H
#define SEAT_H

#include <string>

enum class SeatType {
    Silver,
    Gold,
    Platinum
};

class Seat {
private:
    int seatNo;
    SeatType type;

public:
    Seat(int seatNo, SeatType type);

    int getSeatNo() const;
    SeatType getType() const;
    double getPrice() const;
    std::string getTypeName() const;
};

#endif
