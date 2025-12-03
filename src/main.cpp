#include "Date.hpp"
#include <iostream>

int main() {
    Date date{2, DateMembers::Month{10}, DateMembers::Year{2000}};
    std::cout << date;
}