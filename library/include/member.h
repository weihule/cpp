#pragma once

#include <string>
#include <vector>
#include "Book.h"


class Member {
private:
	int memberID;
	std::string name;
	std::string email;
	std::vector<int> borrowedBooks;  // 存储借出的书籍ID
	int maxBooks;	// 最多能借的书数

public:
	// 构造函数
	Member();
	Member(int id, std::string name, std::string email);

	// Getter
	[[nodiscard]] int getID() const { return memberID; }
	[[nodiscard]] std::string getName() const { return name; }
	[[nodiscard]] std::string getEmail() const { return email; }
	[[nodiscard]] std::vector<int> getBorrowedBooks() const { return borrowedBooks; }
	[[nodiscard]] size_t getBorrowCount() const { return borrowedBooks.size(); }

	// 借
	bool borrowBook(int bookID);

	// 还
	bool returnBook(int bookID);

	// 检查是否可以再借
	[[nodiscard]] bool canBorrow() const { return borrowedBooks.size() < maxBooks; }

	// 显示会员信息
	void display() const;
};
