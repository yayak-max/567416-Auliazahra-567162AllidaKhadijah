#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "User.h"
#include "Library.h"
using namespace std;

vector<User> loadUsers() {
    vector<User> users;
    ifstream file("users.txt");

    string username, password;
    while (file >> username >> password) {
        users.push_back(User(username, password));
    }
    return users;
}

void saveUser(User &u) {
    ofstream file("users.txt", ios::app);
    file << u.username << " " << u.password << "\n";
}

int main() {
    vector<User> users = loadUsers();
    Library lib;

    string u, p;
    cout << "=== REGISTRASI USER ===\n";
    cout << "Buat Username: ";
    cin >> u;
    cout << "Buat Password: ";
    cin >> p;
    users.push_back(User(u, p));
    saveUser(users.back());

    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    bool loginSuccess = false;
    for (User &usr : users) {
        if (usr.login(u, p)) loginSuccess = true;
    }
    if (!loginSuccess) {
        cout << "Login gagal!\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Lihat Buku\n";
        cout << "3. Pinjam Buku\n";
        cout << "4. Kembalikan Buku\n";
        cout << "5. Cari Buku\n";
        cout << "0. Keluar\n";

        cin >> pilihan;

        switch (pilihan) {
        case 1: lib.addBook(); break;
        case 2: lib.showBooks(); break;
        case 3: lib.borrowBook(); break;
        case 4: lib.returnBook(); break;
        case 5: lib.searchBook(); break;
        case 0: cout << "Keluar...\n"; break;
        default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
