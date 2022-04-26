#include <iostream>
#include "Cursor.h"
using namespace std;

int main()
{
	cout << Object::Count() << endl;
	Cursor c = { {100, 100}, 8, false };
	c.move(-10, 10);
	cout << c << endl;
	cout << Object::Count() << endl;

	return 0;
}