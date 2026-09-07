#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string phone;

public:
    Customer(const std::string& name, const std::string& phone);

    std::string getName() const;
    std::string getPhone() const;
};

#endif
