// Example 13-15: obj ptr
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstring>
using namespace std;

class Book {
private:
	long index;
	char name[30];
public:
	Book(const char * i_name) : index(-1) {
		strcpy(name, i_name);
	}
	void show_data() {
		cout << "name: " << name << " index: " << index << endl;
	}
};
int main() {
	Book A_Book("The C++ Bible");
	Book *book_ptr = &A_Book;

	book_ptr->show_data();

	system("pause");
	return 0;
}