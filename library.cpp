#include "Library.h"
#include <fstream>
#include <sstream>
#include <iostream>

Library::Library() {
    loadBooks();
}

void Library::loadBooks() {
    ifstream file("books.txt");
    if (!file) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id, status;
        string title, author;

        ss >> id;
        ss.ignore();
        getline(ss, title, ';');
        getline(ss, author, ';');
        ss >> status;

        books.push_back(Book(id, title, author, status));
    }
    file.close();
}

void Library::saveBooks() {
    ofstream file("books.txt");
    for (Book &b : books) {
        file << b.id << " " << b.title << ";" << b.author << ";" << b.isBorrowed << "\n";
    }
    file.close();
}

void Library::addBook() {
    int id;
    string title, author;

    cout << "Masukkan ID: ";
    cin >> id; cin.ignore();
    cout << "Masukkan Judul: ";
    getline(cin, title);
    cout << "Masukkan Penulis: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));
    saveBooks();

    cout << "Buku berhasil ditambahkan!\n";
}

void Library::showBooks() {
    if (books.empty()) {
        cout << "Tidak ada buku.\n";
        return;
    }
    cout << "\n=== DAFTAR BUKU ===\n";
    for (Book &b : books) b.display();
}

void Library::borrowBook() {
    int id;
    cout << "Masukkan ID buku: ";
    cin >> id;

    for (Book &b : books) {
        if (b.id == id) {
            if (!b.isBorrowed) {
                b.isBorrowed = true;
                saveBooks();
                cout << "Buku berhasil dipinjam!\n";
            } else {
                cout << "Buku sedang dipinjam.\n";
            }
            return;
        }
    }
    cout << "Buku tidak ditemukan!\n";
}

void Library::returnBook() {
    int id;
    cout << "Masukkan ID buku: ";
    cin >> id;

    for (Book &b : books) {
        if (b.id == id) {
            if (b.isBorrowed) {
                b.isBorrowed = false;
                saveBooks();
                cout << "Buku berhasil dikembalikan!\n";
            } else {
                cout << "Buku tidak sedang dipinjam.\n";
            }
            return;
        }
    }
    cout << "Buku tidak ditemukan!\n";
}

void Library::searchBook() {
    cin.ignore();
    string keyword;
    cout << "Masukkan judul/penulis: ";
    getline(cin, keyword);

    bool found = false;
    for (Book &b : books) {
        if (b.title.find(keyword) != string::npos ||
            b.author.find(keyword) != string::npos) 
        {
            b.display();
            found = true;
        }
    }
    if (!found) cout << "Tidak ditemukan.\n";
}
