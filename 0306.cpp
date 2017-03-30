 #include<iostream>
using namespace std;
class Printer {
public:
	int stdID;
	char name[7];
	int grade;
	char exp[300];
	void hello() {
		cout << "------------------------------------\n";
		cout << "Student_Id: " << stdID << endl;
		cout << "name: " << name << endl;
		cout << "I am a " << grade << " grades student in YZU" << endl;
		cout << "I look forward to" << endl << exp << endl << "in the class" << endl;
	};
};

int main() {
	Printer me;
	cout << "My Student_Id: ";
	cin >> me.stdID;
	cout << "My name is: ";
	cin >> me.name;
	cout << "My grade is: ";
	cin >> me.grade;
	cout << "My expection is: ";
	cin >> me.exp;

	me.hello();
	system("pause");
	return 0;
}
