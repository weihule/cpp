#pragma once

#include <vector>
#include <map>
#include <string>
#include "book.h"
#include "member.h"

class Library {
private:
    std::string libraryName;
    std::vector<Book> books;
    std::map<int, Member> members;
    std::map<int, int> borrowRecords;

public:
    Library(std::string name);

    // book manager
    void addBook(const Book& book);
    void removeBook(int bookID);
    Book* findBook(int bookID);

    // person manager
    void addMember(const Member& member);
    void removeMember(int memberID);
    Member* findMember(int memberID);

    // borrow and return
    bool borrowBook(int memberID, int bookID);
    bool returnBook(int memberID, int bookID);

    // query
    void searchByTitle(const std::string& title);
    void searchByAuthor(const std::string& author);
    void listAllBooks() const;
    void listAllMembers() const;
    void showBorrowRecords() const;

    // display library information
    void display() const;

};
