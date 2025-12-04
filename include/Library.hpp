#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <vector>
#include "Book.hpp"
#include "Patron.hpp"

namespace LibraryMembers {
    struct Transaction {
        Book book;
        Patron patron;
        Date date;
    };
};

class Library {
public:
    class Invalid{};
    void AddBook(const Book &book);
    void AddPatron(const Patron &patron);
    void CheckOutBook(const Book &book, const Patron &patron);
    std::vector<std::string> PatronsWhoOwnFees() const;

private:
    bool HasBook(const Book &book);
    bool HasPatron(const Patron &patron);
    std::vector<std::unique_ptr<Book>> books;
    std::vector<std::unique_ptr<Patron>> patrons;
    std::vector<std::unique_ptr<LibraryMembers::Transaction>> transactions;
};

#endif 