#include <iostream>
#include <algorithm>
#include "library.h"

Library::Library(std::string name)
	:libraryName(std::move(name)){}

void Library::addBook(const Book &book) {
	books.push_back(book);
	std::cout << "✓ 书籍 " << book.getTitle() << " 已添加\n!";
}

void Library::removeBook(int bookID) {
	auto it = std::find_if(books.begin(), books.end(),
		[bookID](const Book& b){return b.getID() == bookID;});

	if (it != books.end()) {
		books.erase(it);
		std::cout << "✓ 书籍已删除\n";
	} else {
		std::cout << "✗ 找不到该书籍\n";
	}
}

Book* Library::findBook(int bookID) {
	auto it = std::find_if(books.begin(), books.end(),
		[bookID](const Book& b){return b.getID() == bookID;});
	return (it != books.end()) ? &(*it) : nullptr;
}

void Library::addMember(const Member &member) {
	members[member.getID()] = member;
	std::cout << "✓ 会员 '" << member.getName() << "' 已注册\n";
}

Member* Library::findMember(int memberID) {
	auto it = members.find(memberID);
	return (it != members.end()) ? &(it->second) : nullptr;
}

bool Library::borrowBook(int memberID, int bookID) {
	Member* member = findMember(memberID);
	Book* book = findBook(bookID);

	if (!member) {
		std::cout << "✗ 会员不存在\n";
		return false;
	}

	if (!book) {
		std::cout << "✗ 书籍不存在\n";
		return false;
	}

	if (!book->getAvailable()) {
		std::cout << "✗ 书籍已被借出\n";
		return false;
	}

	if (!member->canBorrow()) {
		std::cout << "✗ 会员借书数已达上限\n";
		return false;
	}

	// 执行借书
	member->borrowBook(bookID);
	book->setAvailable(false);
	borrowRecords[bookID] = memberID;

	std::cout << "✓ 借书成功! 会员: " << member->getName()
	<< "借出: " << book->getTitle() << "\n";
	return true;
}

bool Library::returnBook(int memberID, int bookID) {
	Member* member = findMember(memberID);
	Book* book = findBook(bookID);

	if (!member || !book) {
		std::cout << "✗ 会员或书籍不存在\n";
		return false;
	}

	if (book->getAvailable()) {
		std::cout << "✗ 该书籍未被借出\n";
		return false;
	}

	if (!member->returnBook(bookID)) {
		std::cout << "✗ 该会员未借此书\n";
		return false;
	}

	book->setAvailable(true);
	borrowRecords.erase(bookID);

	std::cout << "✓ 还书成功! 会员: " << member->getName()
	           << "归还: " << book->getTitle() << "\n";
	return true;
}

void Library::searchByTitle(const std::string& title) {
	std::cout << "\n--- 按书名搜索: " << title << " ---\n";
	bool found = false;
	for (const auto& book: books) {
		if (book.matchAuthor(title)) {
			book.display();
			found = true;
		}
	}
	if (!found) {
		std::cout << "未找到相关书籍！" << "\n";
	}
}

void Library::searchByAuthor(const std::string &author) {
	std::cout << "\n--- 按作者搜索: " << author << " ---\n";
	bool found = false;
	for (const auto& book: books) {
		if (book.matchAuthor(author)) {
			book.display();
			found = true;
		}
	}
	if (!found) {
		std::cout << "未找到相关书籍！" << "\n";
	}
}

void Library::listAllBooks() const {
	std::cout << "\n========== 图书馆藏书 ==========\n";
	std::cout << "共 " << books.size() << " 本书！\n";
	for (const auto& book: books) {
		book.display();
	}
	std::cout << "================================\n";
}


void Library::listAllMembers() const {
	std::cout << "\n========== 会员列表 ==========\n";
	std::cout << "共 " << members.size() << " 位会员\n";
	for (const auto& member: members) {
		member.second.display();
	}
}

void Library::showBorrowRecords() const {
	std::cout << "\n========== 借书记录 ==========\n";
	if (borrowRecords.empty()) {
		std::cout << "暂无借书记录！\n";
	}else {
		for (const auto& record: borrowRecords) {
			std::cout << "书籍ID: " << record.first << " <- 会员ID: " << record.second << "\n";
		}
	}
	std::cout << "================================\n";
}

void Library::display() const {
	std::cout << "图书馆名称: " << libraryName << "\n";
	std::cout << "书籍总数: " << books.size() << "\n";
	std::cout << "会员总数: " << members.size() << "\n";
	std::cout << "借出中: " << borrowRecords.size() << "\n";
}

static void test() {
	std::string title = "this is a book !";

	size_t pos = title.find("book1");

	std::cout << "pos = " << pos << std::endl;
}





