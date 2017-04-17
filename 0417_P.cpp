#include <iostream>
#include <cstring>
using namespace std;
class battle
{
private:
	long index;

public:

	void show()
	{
		cout << index << endl;
	}

	battle *set(int i_index)
	{
		index = i_index;
		return this;
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	battle object, *object_ptr;
	object_ptr = object.set(1);
	cout << &object << endl;
	cout << object_ptr << endl;
	object.set(2)->show();
	system("pause>nul");
	return 0;
}