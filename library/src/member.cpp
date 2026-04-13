#include "member.h"
#include <algorithm>

Member::Member(int id, std::string name, std::string email)
    : memberID(id), name(std::move(name)), email(std::move(email)), maxBooks(5){}

bool Member::borrowBook(int bookID) {
    if (borrowedBooks.size() < maxBooks) {
        borrowedBooks.push_back(bookID);
        return true;
    }
    return false;
}

bool Member::returnBook(int bookID) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookID);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        return true;
    }
    return false;
}

void Member::display() const {
    std::cout << "会员ID: " << memberID
         << " | 姓名: " << name
         << " | 邮箱: " << email
         << " | 已借书籍数: " << borrowedBooks.size() << "/" << maxBooks << "\n";
    if (!borrowedBooks.empty()) {
        std::cout << "    已借书籍ID: ";
        for (int id: borrowedBooks) {
            std::cout << id << " ";
        }
        std::cout << "\n";
    }
}



