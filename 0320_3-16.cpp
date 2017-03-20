// Exp 8-22
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

class Fib {
private:
	int F0, F1, Fn, n;
public:
	Fib(int num);
	int fib(int num);
	void show_data();
};

Fib::Fib(int num): F0(0), F1(1), n(num) {
	if (num == 0) Fn = F0;
	if (num == 1) Fn = F1;
	else Fn = fib(n);
}

int Fib::fib(int num) {
	if (num == 0)
		return F0;
	if (num == 1)
		return F1;
	return fib(num - 1) + fib(num - 2);
}

void Fib::show_data(){
	cout << "F" << n << ": " << Fn;
}

int main() {
	int num;
	cout << "n = ";
	cin >> num;

	Fib * Fib_ptr = new Fib(num);
	Fib_ptr->show_data();

	delete Fib_ptr;

	system("pause");
	return 0;
}