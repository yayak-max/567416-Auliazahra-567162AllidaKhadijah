#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"

class Library {
private:
    vector<Book> books;
    void loadBooks();
    void saveBooks();

public:
    Library();
    void addBook();
    void showBooks();
    void borrowBook();
    void returnBook();
    void searchBook();
};

#endif
