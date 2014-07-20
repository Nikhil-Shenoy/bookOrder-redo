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
	Customer *four = new Customer("Rohit",4,400.00,"1 Sunset Court","NJ","08550");
	Customer *five = new Customer("Mukunda",5,500.00,"34 Hawthorne Drive","NJ","08550");
	
	Customer *found;

	myList.insert(five);
	myList.insert(two);
	myList.insert(three);
	myList.insert(one);
	myList.insert(four);

	found = myList.find(2);

	myList.remove(2);
	myList.remove(5);
	myList.remove(4);
	myList.remove(1);
	myList.remove(3);
	myList.remove(4);
	myList.print();

	

//	found->print();	

	cout << "The size is: " << myList.getSize() << endl;
/*
	delete one;
	delete two;
	delete three;
	delete four;
	delete five;
*/	
	return 0;
}
	
