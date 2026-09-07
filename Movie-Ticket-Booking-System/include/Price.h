#ifndef PRICE_H
#define PRICE_H

#include "Show.h"
#include <vector>

class Price {
public:
    static double calculateTotal(const std::vector<ShowSeat*>& seats);
};

#endif
