#include "Price.h"

double Price::calculateTotal(const std::vector<ShowSeat*>& seats) {
    double total = 0.0;
    for (const auto* showSeat : seats) {
        total += showSeat->seat->getPrice();
    }
    return total;
}
