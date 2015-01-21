#include <iostream>
#include "Utility.h"
using namespace std;

void main()
{

	int a = 2;
	int b = 7;

	cout << Add(a, b) << endl;

	cout << Clamp(6, 3, a);
	cout << Clamp(6, 3, b);

	getchar();
}
