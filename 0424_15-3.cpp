// Pra 15-3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base's constructor is called!\n"; };
};

class Composition_1 {
public:
    Composition_1() { cout << "Composition_1 constructor is called!\n"; }
    void show() { cout << "Composition_1::show is called!\n"; };
};

class Composition_2 {
public:
    Composition_2() { cout << "Composition_2 constructor is called!\n"; }
    void show() { cout << "Composition_2::show is called!\n"; };
};

class Derived : public Base {
public:
    // 重點一：以物件指標、參考、指標建立的，被包含的建構子不會被呼叫
    Composition_2 * com_2;
    Composition_1 & com_1;
    
    Derived(Composition_1 & com_1_ref, Composition_2 * com_2_ptr)
    : com_1(com_1_ref), com_2(com_2_ptr) {
        cout << "Derived's constructor is called!\n";
    }
    Derived(Composition_1 & com_1_ref) : com_1(com_1_ref) {
        cout << "Derived's constructor is called!\n";
    }
};

int main() {
    Composition_1 com_1; // 1
    Composition_2 com_2; // 2
    
    Derived derived_obj1(com_1, &com_2); // 3
    Derived derived_obj2(com_1); // 4
    
    cout << endl;
    derived_obj1.com_1.show();
    
    cout << endl;
    derived_obj2.com_2->show();
    
    system("PAUSE");
    return 0;
}
/* Output -----------------------
 Composition_1 constructor is called! // 1
 Composition_2 constructor is called! // 2
 Base's constructor is called! // 3
 Derived's constructor is called! // 3
 Base's constructor is called! // 4
 Derived's constructor is called! // 4
 
 Composition_1::show is called!
 
 Composition_2::show is called!
 ------------------------------ */
