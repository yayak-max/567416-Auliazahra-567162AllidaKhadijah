#include "User.h"

User::User(string u, string p) {
    username = u;
    password = p;
}

bool User::login(string u, string p) {
    return (u == username && p == password);
}
