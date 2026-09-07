#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& phone)
    : name(name), phone(phone) {}

std::string Customer::getName() const { return name; }
std::string Customer::getPhone() const { return phone; }
