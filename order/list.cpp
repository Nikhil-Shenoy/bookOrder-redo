#include <iostream>
#include <string>
#include "order.h"
#include "orderList.h"
using namespace std;

int main()
{
	OrderList myList;	
	
	Order *one = new Order("The Count of Monte Cristo",10.00,1,"suspense");
	Order *two = new Order("1984",11.00,2,"thriller");
	Order *three = new Order("Linear Dynamic Systems and Signals",12.00,3,"textbook");
	Order *four = new Order("The New York Times",13.00,4,"newspaper");
	Order *five = new Order("Leaves From the Vine",14.00,5,"grief");
	
	Order *found;

	myList.insert(five);
	myList.insert(two);
	myList.insert(three);
	myList.insert(one);
	myList.insert(four);

	found = myList.find(2);

	myList.remove(2);
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
	
