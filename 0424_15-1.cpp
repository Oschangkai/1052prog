// Pra 15-1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Tire {
private:
    char size[10];
    
public:
    Tire(char * i_size) { strcpy(size, i_size); };
    
    void showData() { cout << "\t\tsize: " << size << endl; }
};
class Car {
private:
    Tire **Tires;
    int intTireNum;
    char brand[20];
    
public:
    Car(char* ibrand, Tire** aryTires, int iTireNum) {
        strcpy(brand, ibrand);
        Tires = aryTires;
        intTireNum = iTireNum;
    }
    
    void showData() {
        cout << "Output Car Obj data-------\n";
        cout << "\tbarnd: " << brand << endl;
        for (int i = 0; i < intTireNum; i++) {
            (*(Tires + i))->showData();
        }
    }
};
class Eye {
private:
    char color[10];
public:
    Eye(char* i_color) {
        cout << "Initialize Eye obj.....\n";
        strcpy(color, i_color);
    }
    void showData() { cout << "\t\teye color: " << color << endl; }
};
class Person {
private:
    char name[10];
    char sex;
    Eye myEye;
    Car * myCar;
public:
    Person(char* i_name, char i_sex, char* eyecolor) : myEye(eyecolor), sex(i_sex) {
        cout << "Initialize Person Obj......\n";
        strcpy(name, i_name);
    }
    void setCar(Car* aCar) { myCar = aCar; };
    void showData() {
        cout << "\n\nOutput Person obj data -----\n";
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        
        myEye.showData();
        cout << endl;
        
        myCar->showData();
    }
};

int main() {
    char name[20] = "John", eyecolor[10] = "black";
    Person john(name, 'M', eyecolor);
    Tire* aryTires[4]; // 類別陣列
    aryTires[0] = new Tire("235/45/17");
    aryTires[1] = new Tire("235/45/17");
    aryTires[2] = new Tire("225/40/17");
    aryTires[3] = new Tire("225/40/17");
    
    char carbrand[10] = "BMW";
    // aryTires[n] 的大小 = char[10] * n
    // 所以計算的時候要把他除掉
    Car aCar(carbrand, aryTires, sizeof(aryTires) / sizeof(aryTires[0]));
    john.setCar(&aCar);
    john.showData();
    system("PAUSE");
    return 0;
}
/* Output -----------------------
 Initialize Eye obj.....
 Initialize Person Obj......
 
 
 Output Person obj data -----
 Name: John
 Sex: M
 eye color: black
 
 Output Car Obj data-------
 barnd: BMW
 size: 235/45/17
 size: 235/45/17
 size: 225/40/17
 size: 225/40/17
 ------------------------------ */
