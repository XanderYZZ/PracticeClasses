#ifndef PATRON_HPP
#define PATRON_HPP
#include <string>

class Patron {
public:
    Patron(const std::string &name, const int &card_number, const double &fees) : name(name), card_number(card_number), fees(fees) {}
    std::string GetName() const { return name; }
    int GetCardNumber() const { return card_number; }
    double GetFees() const { return fees; }
    void SetFees(const double &fees) { this->fees = fees; }
    bool OwesFee() const { return fees > 0; }
    bool operator==(const Patron &other) const {
        return card_number == other.GetCardNumber();
    }
    bool operator!=(const Patron &other) const {
        return !(*this == other);
    }

private:
    std::string name;
    int card_number;
    double fees;
};

#endif 