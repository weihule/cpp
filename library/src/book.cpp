#include "book.h"

Book::Book(int id, std::string title, std::string author, std::string isbn)
	: bookID(id), title(title), author(author), isbn(isbn), isAvailable(true) {}

void Book::display() const {
	std::cout << "ID: " << bookID
			<< " | 书名: " << title
			<< " | 作者: " << author
			<< " | ISBN: " << isbn
	        << " | 状态: " << (isAvailable ? "可借" : "已借出") << "\n";
}


bool Book::matchTitle(const std::string& searchTitle) const {
	return title.find(searchTitle) != std::string::npos;
}

bool Book::matchAuthor(const std::string& searchAuthor) const {
	return author.find(searchAuthor) != std::string::npos;
}





