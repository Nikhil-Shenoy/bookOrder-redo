#include <iostream>
#include <string>
#include "customer.h"
#include "customerList.h"
using namespace std;

int main()
{
	CustomerList myList;	
	
	Customer *one = new Customer("Nikhil",1,100.00,"1 Country Squire Lane","NJ","08550");
	Customer *two = new Customer("Vineet",2,200.00,"1 Country Squire Lane","NJ","08550");
	Customer *three = new Customer("Rishab",3,300.00,"5 Sunset Court","NJ","08550");
	
	Customer *found;

	myList.insert(two);
	myList.insert(three);
	myList.insert(one);

	found = myList.find(2);

	myList.print();

	found->print();	

	cout << "The size is: " << myList.getSize() << endl;

	delete one;
	delete two;
	delete three;
	
	return 0;
}
	
