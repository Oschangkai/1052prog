// 程式碼來源：https://openhome.cc/Gossip/CGossip/DoublePointer.html
#include <iostream>
using namespace std;

int main() {
    int p = 10;
    int *ptr1 = &p;
    int **ptr2 = &ptr1;
    
    cout << "p 的值：" << p << endl;
    cout << "p 的記憶體位置：" << &p << endl << endl;
    
    cout << "*ptr1 參照的值：" << *ptr1 << endl;
    cout << "ptr1 儲存的位址值：" << ptr1 << endl;
    cout << "ptr1 的記憶體位置：" << &ptr1 << endl << endl;
    
    cout << "**ptr2 = " << **ptr2 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;
    cout << "ptr2 = " << ptr2 << endl << endl;
    
    cout << "整理(誰儲存了誰？)：" << endl;
    cout << "&p = " << &p << "\t" << "prt1 = " << ptr1 << endl;
    cout << "&ptr1 = " << &ptr1 << "\t" << "prt2 = " << ptr2 << endl;
    
    return 0;
}
/* Output -----------------------
 p 的值：10
 p 的記憶體位置：0x7fff5fbff668
 
 *ptr1 參照的值：10
 ptr1 儲存的位址值：0x7fff5fbff668
 ptr1 的記憶體位置：0x7fff5fbff660
 
 **ptr2 = 10
 *ptr2 = 0x7fff5fbff668
 ptr2 = 0x7fff5fbff660
 
 整理(誰儲存了誰？)：
 &p = 0x7fff5fbff668	prt1 = 0x7fff5fbff668
 &ptr1 = 0x7fff5fbff660	prt2 = 0x7fff5fbff660
------------------------------ */
