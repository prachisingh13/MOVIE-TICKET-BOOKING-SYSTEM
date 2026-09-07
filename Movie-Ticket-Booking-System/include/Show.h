#ifndef SHOW_H
#define SHOW_H

#include "Movie.h"
#include "Screen.h"
#include "Types.h"
#include <string>
#include <vector>

struct ShowSeat {
    Seat* seat;
    SeatStatus status;

    bool isAvailable() const;
    void book();
    void release();
};

class Show {
private:
    Movie* movie;
    Screen* screen;
    std::string startTime;
    std::vector<ShowSeat> showSeats;

public:
    Show(Movie* movie, Screen* screen, const std::string& startTime);

    Movie* getMovie() const;
    Screen* getScreen() const;
    std::string getStartTime() const;
    std::vector<ShowSeat>& getShowSeats();

    ShowSeat* findShowSeat(int seatNo);
    void displaySeats() const;
};

#endif
