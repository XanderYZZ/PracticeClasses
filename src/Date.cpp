#include "Date.hpp"

Date::Date(int day, DateMembers::Month month, DateMembers::Year year) {
    if (year.y < 0) {
        throw Invalid{};
    }

    int to_int = static_cast<int>(month);

    if (to_int < 1 || to_int > 12) {
        throw Invalid{};
    }

    // I do not check for the specific day ranges for each month since this is a mock class. 
    if (day < 1 || day > 31) {
        throw Invalid{};
    }

    this->year = year;
    this->month = month;
    this->day = day;
}

std::ostream& operator<<(std::ostream &os, const Date &date) {
    return os << date.GetDay() << "/" << std::to_string(static_cast<int>(date.GetMonth())) << "/" << date.GetYear().y << "\n";

    return os;
}