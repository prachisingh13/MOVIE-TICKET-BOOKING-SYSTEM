#include "Payment.h"
#include <iostream>

bool UPI::pay(double amount) {
    std::cout << "Processing UPI payment of Rs. " << amount << "...\n";
    return true;
}

bool Card::pay(double amount) {
    std::cout << "Processing Card payment of Rs. " << amount << "...\n";
    return true;
}

bool Cash::pay(double amount) {
    std::cout << "Processing Cash payment of Rs. " << amount << "...\n";
    return true;
}
