#include "Date.hpp"
#include "IOTests.hpp"

int main() {
    Date date{2, DateMembers::Month{10}, DateMembers::Year{2000}};
    std::cout << date;
    FindLinesWithWord("withwords.txt", "dog");
    RemoveVowelsFromFile("removevowels.txt");
}