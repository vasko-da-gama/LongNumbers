#include <iostream>
#include "LongNum.h"
using namespace std;
using namespace LongNumbers;

int main(int arc, char* argv[])
{
	cout << "+-- Long Numbers demonstration\n";
	LongNum a, b, c;
	a = (char*) "4200514651850485189505095195085909419125960505608915905050";
	b = 2;

	c = a / b;
	cout << "| a = " << a;
	cout << "| b = " << b;
	cout << "| a / b = " << c;
	cout << "+----------------------------------------------------------------\n";
	cout << "| a = " << a;
	b = (char*) "8978954954954989854652120560594951281";
	cout << "| b = " << b;
	c = a / b;
	cout << "| a / b = " << c;
	cout << "+----------------------------------------------------------------\n";
	cout << "| a = " << a;
	cout << "| b = " << b;
	c = a % b;
	cout << "| a % b = " << c;
	cout << "+----------------------------------------------------------------\n";
	cout << "| a = " << a;
	cout << "| b = " << b;
	c = a * b;
	cout << "| a * b = " << c;
	cout << "+----------------------------------------------------------------\n";
	a = 26718;
	cout << "| a = " << a;
	b = a.fpow(3562);
	cout << "| a.fpow(3562) = " << b;

	return 0;
}