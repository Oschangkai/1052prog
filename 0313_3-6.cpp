#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Reader {
private:
	char * name;
	long len;
	double weight;
	double height;
	double BMI(double weight, double height);
public:
	Reader(char * n, double w, double h);
	void printData();
};
double Reader::BMI(double weight, double height) {
	return (weight / (height * height));
}
Reader::Reader(char * n, double w, double h){
	len = strlen(n);
	name = new char[len + 1];
	strcpy(name, n);

	weight = w;
	height = h;
}
void Reader::printData() {
	cout << "Your input:\n";
	cout << "Name: " << name << "  Length: " << len << endl;
	cout << "Weight: " << weight << endl;
	cout << "Height: " << height << endl;
	cout << "-------------------\n";
	cout << "BMI: " << BMI(weight, height) << endl;
}
int main() {
	char name[10];
	double weight, height;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your weight(kg) and height(m): ";
	cin >> weight >> height;
	cout << "-------------------\n";

	Reader A_person(name, weight, height);
	A_person.printData();
	
	system("pause");
	return 0;
}