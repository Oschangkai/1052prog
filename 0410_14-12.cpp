// Example 14-12
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<cstring>
using namespace std;

class libObj {
protected:
	char name[30];
	long index;
	static char File_Name[20];
public:
	libObj(const char * i_name) {
		strcpy(name, i_name);
		index = 1;
	}
	void show_data() {
		cout << "name: " << name;
		cout << "  index: " << index;
		cout << "  File_name: " << File_Name << endl;
	}
};
char libObj::File_Name[20];

class Book : public libObj {
private:
	bool on_shelf;
public:
	Book(const char * name) : libObj(name) {
		on_shelf = true;
		strcpy(File_Name, "book.txt");
	}
};

class Reader : public libObj {
public:
	Reader(const char * name) : libObj(name) {
		strcpy(File_Name, "reader.txt");
	}
};

int main() {
	Reader A_Reader("John");
	A_Reader.show_data();

	Book A_Book("The C++ Bible");
	A_Reader.show_data();

	system("PAUSE");
	return 0;

}

/* Output -----------------------
name: John  index: 1  File_name: reader.txt
name: John  index: 1  File_name: book.txt
------------------------------ */