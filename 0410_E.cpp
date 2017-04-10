// Exam
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstring>
using namespace std;

class Book {
private:
	static int book_num;
	int index;
	char name[30];
	bool on_shelf;
public:
	Book(const char * i_name, int idx): on_shelf(true), index(idx) {
		strcpy(name, i_name);
		book_num += 1;
	}
	static int get_book_num_static() { return book_num; }
	int get_book_index() { return index; }
	void show_book() {
		cout << "name: " << name << "  index: " << index;
		if (on_shelf)
			cout << " on shelf\n";
		else
			cout << " lend out\n";
	}
	bool lend_out() {
		if (on_shelf) {
			on_shelf = false;
			book_num -= 1;
			return true;
		}
		return on_shelf;
	}
};

void All_show(Book &a, Book &b, Book &c, Book &d) {
	a.show_book();
	b.show_book();
	c.show_book();
	d.show_book();
}

int Book::book_num = 0;
int main() {
	char book_name[30];
	int index = 1;
	int book_n;

	cout << "Book name: \n";
	cin >> book_name;
	Book A_Book(book_name, index++);

	cin >> book_name;
	Book B_Book(book_name, index++);

	cin >> book_name;
	Book C_Book(book_name, index++);

	cin >> book_name;
	Book D_Book(book_name, index++);

	cout << "---------------------------------------\n";
	// 指標物件
	Book * lend_book = &C_Book;
	lend_book->lend_out();
	All_show(A_Book, B_Book, C_Book, D_Book);
	cout << "book(s) on shelf: " << Book::get_book_num_static() << endl;
	system("PAUSE");
	return 0;

}
