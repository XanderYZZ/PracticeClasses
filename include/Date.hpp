#ifndef DATE_HPP
#define DATE_HPP
#include <ostream>
#include <string>

namespace DateMembers {
    struct Year {
        int y;

        bool operator==(const Year &other) const {
            return y == other.y;
        }
    };

    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
};

class Date {
public:
    class Invalid {};
    Date() {};
    Date(int day, DateMembers::Month month, DateMembers::Year year);
    DateMembers::Year GetYear() const { return year; }
    DateMembers::Month GetMonth() const { return month; }
    int GetDay() const { return day; }

    bool operator==(const Date &other) const {
        return GetYear() == other.GetYear() && GetMonth() == other.GetMonth()
        && GetDay() == other.GetDay();
    }

    bool operator!=(const Date &other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream &os, const Date &date);

private:
    DateMembers::Year year{1970};
    DateMembers::Month month{1};
    int day = 1;
};

#endif 