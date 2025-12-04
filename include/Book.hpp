#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include "Date.hpp"

namespace BookMembers {
    enum class Genre {
        fiction = 1, nonfiction, periodical, biography, children
    };
};

class Book {
public:
    class Invalid{};
    Book(const BookMembers::Genre &genre, const std::string &ISBN, const std::string &title, const std::string &author, const Date &copyright_date, const bool &checked_out);
    std::string GetISBN() const { return ISBN; }
    std::string GetTitle() const { return title; }
    std::string GetAuthor() const { return author; }
    bool operator==(const Book &other) const {
        return ISBN == other.GetISBN();
    }
    bool operator!=(const Book &other) const {
        return !(*this == other);
    }
    friend std::ostream& operator<<(std::ostream &os, const Book &book);

private:
    BookMembers::Genre genre;
    std::string ISBN;
    std::string title;
    std::string author;
    Date copyright_date;
    bool checked_out = false;
};

#endif 