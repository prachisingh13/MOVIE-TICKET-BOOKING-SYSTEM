#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
public:
    virtual ~Payment() = default;
    virtual bool pay(double amount) = 0;
};

class UPI : public Payment {
public:
    bool pay(double amount) override;
};

class Card : public Payment {
public:
    bool pay(double amount) override;
};

class Cash : public Payment {
public:
    bool pay(double amount) override;
};

#endif
