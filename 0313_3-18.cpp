#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

class String {
private:
	char * string;
	long len;
public:
	String(const char * i_string); // Constructor
	~String(); // Destructer
	void show_string(); // Print out
};

void String::show_string() {
	cout << "String: " << string << "\tlength: " << len << endl;
}

String::String(const char * i_string) { // Constructer
	cout << "Constructer is called!" << endl;
	len = strlen(i_string);
	string = new char[len + 1];
	strcpy(string, i_string);
}

String::~String() {
	cout << "Destructer is called!" << endl;
	delete[] string;
}

int main() {
	String * A_string = new String("My String");

	A_string->show_string();
	delete A_string;
	system("pause");
	return 0;
}

