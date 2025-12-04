#include "Book.hpp"
#include <vector>
#include <algorithm>

Book::Book(const BookMembers::Genre &genre, const std::string &ISBN, const std::string &title, const std::string &author, const Date &copyright_date, const bool &checked_out) {
    std::vector<std::string> parts;
    std::string curr;

    for (int i = 0; i < ISBN.size(); i++) {
        if (ISBN[i] == '-') {
            parts.emplace_back(curr);
            curr = "";
        } else {
            curr += ISBN[i];
        }
    }

    if (curr != "") {
        parts.emplace_back(curr);
    }

    if (parts.size() != 4) {
        throw Invalid{};
    }

    for (int i = 0; i < parts.size() - 1; i++) {
        curr = parts[i];

        if (curr.empty()) {
            throw Invalid{};
        }

        if (!std::all_of(curr.begin(), curr.end(), [](unsigned char c){ return std::isdigit(c); })) {
            throw Invalid{};
        }
    }

    std::string last = parts[parts.size() - 1];

    if (last.size() != 1) {
        throw Invalid{};
    }

    char l = last[0];

    if (!std::isalpha(l) && !std::isdigit(l)) {
        throw Invalid{};
    }

    this->genre = genre;
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->copyright_date = copyright_date;
    this->checked_out = checked_out;
}

std::ostream& operator<<(std::ostream &os, const Book &book) {
    return os << book.GetTitle() << " by " << book.GetAuthor() << " (ISBN: " << book.GetISBN() << ")\n";

    return os;
}