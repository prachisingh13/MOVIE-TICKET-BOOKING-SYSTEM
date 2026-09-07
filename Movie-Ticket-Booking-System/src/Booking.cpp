#include "Booking.h"

Booking::Booking(int bookingId, Customer* customer, Show* show,
                 const std::vector<ShowSeat*>& seats, double totalAmount)
    : bookingId(bookingId), customer(customer), show(show),
      seats(seats), totalAmount(totalAmount),
      status(BookingStatus::Pending) {}

bool Booking::confirm() {
    for (auto* seat : seats) {
        if (!seat || !seat->isAvailable()) {
            fail();
            return false;
        }
    }

    for (auto* seat : seats) {
        seat->book();
    }

    status = BookingStatus::Confirmed;
    return true;
}

void Booking::cancel() {
    if (status == BookingStatus::Confirmed) {
        for (auto* seat : seats) {
            seat->release();
        }
    }
    status = BookingStatus::Cancelled;
}

void Booking::fail() {
    for (auto* seat : seats) {
        if (seat) seat->release();
    }
    status = BookingStatus::Failed;
}

int Booking::getBookingId() const { return bookingId; }
Customer* Booking::getCustomer() const { return customer; }
Show* Booking::getShow() const { return show; }
const std::vector<ShowSeat*>& Booking::getSeats() const { return seats; }
double Booking::getTotalAmount() const { return totalAmount; }
BookingStatus Booking::getStatus() const { return status; }
