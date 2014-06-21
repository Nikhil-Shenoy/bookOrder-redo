#include <iostream>
#include <string>
#include "order.h"
using namespace std;

int main()
{
	Order first("1984",7.99,1,"politics");

	cout << "Let's see the contents of this order:\n";
	cout << "\tTitle: " << first.getTitle() << "\n";
	cout << "\tPrice: $" << first.getPrice() << "\n";
	cout << "\tID: " << first.getID() << "\n";
	cout << "\tCategory: " << first.getCategory() << "\n";
	cout << "\tNext: " << first.getNext() << "\n";

	cout << "\n";

	cout << "Now let's change what's inside the thing\n";

	Order second("a",2.4,3,"something");

	first.setTitle("The Namesake");
	first.setPrice(5.99);
	first.setID(2);
	first.setCategory("Housing");
	first.setNext(&second);

	cout << "\n\nLet's see the contents of this order:\n";
	cout << "\tTitle: " << first.getTitle() << "\n";
	cout << "\tPrice: $" << first.getPrice() << "\n";
	cout << "\tID: " << first.getID() << "\n";
	cout << "\tCategory: " << first.getCategory() << "\n";
	cout << "\tNext: " << first.getNext() << "\n";


	return 0;
}
