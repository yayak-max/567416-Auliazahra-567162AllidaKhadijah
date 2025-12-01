#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int id=0, string title="", string author="", bool status=false);
    void display();
};

#endif
