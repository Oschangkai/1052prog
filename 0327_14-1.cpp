// 03/27 Test
// Example 14-1 ~ 14-3: Class Inherit

#include <iostream>
using namespace std;

class Base {
private:
    int privateAttribute;
    void privteShow() {
        cout << "privateShow() is called\n";
    }
protected:
    int protectAttribute;
    void protectShow() {
        cout << "protectShow() is called\n";
    }
public:
    int publicAttribute;
    void publicShow() {
        cout << "publicShow() is called\n";
    }
    Base(): privateAttribute(1), protectAttribute(2), publicAttribute(3) { }
};

class Derived: protected Base { // Note: Default private members
public:
    void callFunc() {
        cout << "\nDerived callFunc() called\n";
        publicShow();
        protectShow();
    }
    void showAttr() {
        cout << "\nDerived showAttr() called\n";
        cout << "publicAttribute = " << publicAttribute << endl;
        cout << "protectAttribute = " << protectAttribute << endl;
    }
};

class secondDerived: private Derived {
public:
    void callFunc() {
        cout << "\nsecondDerived callFunc() called\n";
        publicShow();
        protectShow();
    }
    void showAttr() {
        cout << "\nsecondDerived showAttr() called\n";
        cout << "publicAttribute = " << publicAttribute << endl;
        cout << "protectAttribute = " << protectAttribute << endl;
    }
};

class thirdDerived: public secondDerived {
public:
    void callFunc() {
        cout << "\nthirdDerived callFunc() called\n";
        //publicShow();
        //protectShow();
    }
    void showAttr() {
        cout << "\nthirdDerived showAttr() called\n";
        //cout << "publicAttribute = " << publicAttribute << endl;
        //cout << "protectAttribute = " << protectAttribute << endl;
    }
};

int main() {
    Derived derived;
    derived.callFunc();
    derived.showAttr();
    cout << "=======================\n";
    
    secondDerived secDerived;
    secDerived.callFunc();
    secDerived.showAttr();
    cout << "=======================\n";
    
    
    thirdDerived thridDerived;
    thridDerived.callFunc();
    thridDerived.showAttr();
    return 0;
}

/* Output ---------------------
 
 Derived callFunc() called
 publicShow() is called
 protectShow() is called
 
 Derived showAttr() called
 publicAttribute = 3
 protectAttribute = 2
 =======================
 
 secondDerived callFunc() called
 publicShow() is called
 protectShow() is called
 
 secondDerived showAttr() called
 publicAttribute = 3
 protectAttribute = 2
 =======================
 
 thirdDerived callFunc() called
 
 thirdDerived showAttr() called
 
 ------------------------------ */
