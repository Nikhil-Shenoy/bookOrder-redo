#include <iostream>
#include <string>
#include "order.h"
using namespace std;

int main()
{
	Order first("1984",7.99,1,"politics");

	cout << "Let's see the contents of this order:\n";
	first.print();
	cout << "\n";

	cout << "Now let's change what's inside the thing\n";

	Order second("a",2.4,3,"something");

	first.setTitle("The Namesake");
	first.setPrice(5.99);
	first.setID(2);
	first.setCategory("Housing");
	first.setNext(&second);

	cout << "\n\nLet's see the contents of this order:\n";
	first.print();

	cout << "\n Now we're going to test the scope of the object\n";


	return 0;
}
