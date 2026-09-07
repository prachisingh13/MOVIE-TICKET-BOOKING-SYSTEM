#ifndef BOOKING_H
#define BOOKING_H

#include "Customer.h"
#include "Show.h"
#include "Types.h"
#include <vector>

class Booking {
private:
    int bookingId;
    Customer* customer;
    Show* show;
    std::vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(int bookingId, Customer* customer, Show* show,
            const std::vector<ShowSeat*>& seats, double totalAmount);

    bool confirm();
    void cancel();
    void fail();

    int getBookingId() const;
    Customer* getCustomer() const;
    Show* getShow() const;
    const std::vector<ShowSeat*>& getSeats() const;
    double getTotalAmount() const;
    BookingStatus getStatus() const;
};

#endif
