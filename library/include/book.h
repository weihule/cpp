#pragma once

#include <string>
#include <iostream>

class Book {
private:
	int bookID;
	std::string title;
	std::string author;
	std::string isbn;
	bool isAvailable;

public:
	// 构造函数
	Book(int id, std::string title, std::string author, std::string idbn);

	// Getter
	int getID() const { return bookID; }
	std::string getTitle() const { return title; }
	std::string getAuthor() const { return author; }
	std::string getISBN() const { return isbn; }
	bool getAvailable() const { return isAvailable; }

	// 设置可用状态
	void setAvailable(bool available) { isAvailable = available; }

	// 显示信息
	void display() const;

	// 判断是否匹配搜索条件
	bool matchTitle(const std::string& searchTitle) const;
	bool matchAuthor(const std::string& searchAuthor) const;
};