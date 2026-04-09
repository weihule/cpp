#pragma once

#include <string>
#include <vector>
#include "Book.h"


class Member {
private:
	int memberID;
	std::string name;
	std::string email;
	std::vector<int> borrowedBooks;  // 存储借出ID
	int maxBooks;	// 最多借出数

public:
	// 构造函数
	Member(int id, std::string name, std::string email);

	// Getter
	int getID() const { return memberID; }
	std::string getName() const { return name; }
	std::string getEmail() const { return email; }
	std::vector<int> getBorrowedBooks() const { return borrowedBooks; }
	int getBorrowCount() const { return borrowedBooks.size(); }

	// 借操作
	bool borrowBook(int bookID);

	// 还操作
	bool returnBook(int bookID);

	// 检查是否可以再借
	bool canBorrow() const { return borrowedBooks.size() < maxBooks; }

	// 显示信息
	void display() const;
};
