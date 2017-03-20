// Example 13-14: static member
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

class Book {
private:
	static int book_num;
	char name[30];
public:
	Book(const char * i_name) {
		book_num += 1;
		strcpy(name, i_name);
	}
	~Book() { book_num -= 1; }

	static int get_book_num_static() { return book_num; }
	int get_book_num() { return book_num; }
};

int Book::book_num = 0;

int main() {
	Book A_Book("The C++ Bible");
	cout << "A_Book.get_book_num() : " << A_Book.get_book_num() << endl;
	cout << "A_Book.get_book_num_static() : " << A_Book.get_book_num_static() << endl;
	cout << "Book::get_book_num_static() : " << Book::get_book_num_static() << endl;

	system("pause");
	return 0;
}