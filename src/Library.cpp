#include "Library.hpp"
#include <algorithm>

template <typename T>
bool contains(const std::vector<std::unique_ptr<T>>& vec, const T &item) {
    return std::any_of(vec.begin(), vec.end(),
        [&](const std::unique_ptr<T> &ptr) { return *ptr == item; });
}

void Library::AddBook(const Book &book) {
    books.push_back(std::make_unique<Book>(book));
}

void Library::AddPatron(const Patron &patron) {
    patrons.push_back(std::make_unique<Patron>(patron));
}

bool Library::HasBook(const Book &book) {
    return contains(books, book);
}

bool Library::HasPatron(const Patron &patron) {
    return contains(patrons, patron);
}

void Library::CheckOutBook(const Book &book, const Patron &patron) {
    if (!HasBook(book)) {
        throw Invalid{};
    }

    if (!HasPatron(patron)) {
        throw Invalid{};
    }

    if (patron.OwesFee()) {
        throw Invalid{};
    }

    LibraryMembers::Transaction trans{book, patron, Date{1, DateMembers::Month{1}, DateMembers::Year{2025}}};
    transactions.push_back(std::make_unique<LibraryMembers::Transaction>(trans));
}

std::vector<std::string> Library::PatronsWhoOwnFees() const {
    std::vector<std::string> patrons_who_own;

    for (const auto &patron : patrons) {
        if (patron->OwesFee()) {
            patrons_who_own.emplace_back(patron->GetName());
        }
    }

    return patrons_who_own;
}