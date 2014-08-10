#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "../order/order.h"
using namespace std;



int main()
{


	Customer *nikhil = new Customer("Nikhil",1,100.0,"a","b","c");

	Order *first = new Order("New York Times",2.00,1,"news");
	Order *second = new Order("1984",11.00,2,"thriller");
	Order *third = new Order("Linear Dynamic Systems and Signals",12.00,3,"textbook");
	Order *fourth = new Order("The Count of Monte Cristo",10.00,4,"suspense");
	Order *fifth = new Order("Leaves from the Vine",14.00,5,"grief");

	nikhil->accept(first);
	nikhil->accept(second);
	nikhil->reject(third);
	nikhil->printAccepted();

	cout << "\n\nRejected orders: \n";
	nikhil->printRejected();

	delete nikhil;
	delete first;
	delete second;
	delete third;
	delete fourth;
	delete fifth;	





	return 0;
}	
