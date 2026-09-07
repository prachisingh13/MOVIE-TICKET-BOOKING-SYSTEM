#ifndef SCREEN_H
#define SCREEN_H

#include "Seat.h"
#include <vector>

class Screen {
private:
    int screenNo;
    std::vector<Seat> seats;

public:
    explicit Screen(int screenNo);

    void addSeat(const Seat& seat);
    int getScreenNumber() const;
    const std::vector<Seat>& getSeats() const;
    Seat* findSeat(int seatNo);
};

#endif
