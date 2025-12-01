#include "Book.h"

Book::Book(int id, string title, string author, bool status) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->isBorrowed = status;
}

void Book::display() {
    cout << "ID: " << id
         << " | Judul: " << title
         << " | Penulis: " << author
         << " | Status: " << (isBorrowed ? "Dipinjam" : "Tersedia")
         << endl;
}
