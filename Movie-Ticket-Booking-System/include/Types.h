#ifndef TYPES_H
#define TYPES_H

#include <string>

enum class SeatStatus {
    Available,
    Booked
};

enum class BookingStatus {
    Pending,
    Confirmed,
    Cancelled,
    Failed
};

inline std::string seatStatusToString(SeatStatus status) {
    return status == SeatStatus::Available ? "Available" : "Booked";
}

inline std::string bookingStatusToString(BookingStatus status) {
    switch (status) {
        case BookingStatus::Pending: return "Pending";
        case BookingStatus::Confirmed: return "Confirmed";
        case BookingStatus::Cancelled: return "Cancelled";
        case BookingStatus::Failed: return "Failed";
    }
    return "Unknown";
}

#endif
