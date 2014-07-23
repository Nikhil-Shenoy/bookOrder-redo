#include <iostream>
#include <string>
#include "order.h"
#include "orderList.h"
#include "../customer/customerList.h"
#include "../customer/customer.h"
using namespace std;

double total;

void process(Order *purchase, CustomerList myList)
{
	Customer *buyer = myList.find(purchase->getID());

	double price = purchase->getPrice();
	double credit = buyer->getCredit();

	if(credit >= price)
	{
		credit = credit - price;
		buyer->setCredit(credit); // new credit after successful purchase
		cout << "\nOrder approved. Details: \n";
		purchase->print();
		buyer->accept(purchase);
		
		/* need to increment the global total by price, but need to wrap it in a mutex */
	}
	else if(credit < price)
	{
		cout << "\nNot enough credit to make purchase\n";
		buyer->reject(purchase);
	}
}
		
			

int main()
{

	CustomerList database;

	Customer *brian = new Customer("Brian",1,500.00,"110 Frelinghuysen Rd., Piscataway","New Jersey","08554");
	Customer *ying = new Customer("Ying Zhan",2,65.00,"3100 Hamilton Blvd, South Plainfield","New ersey","07080");
	Customer *sejong = new Customer("Sejong Yoon",3,10.00,"200 Promenade Boulevard, Bridgewater","New Jersey","08807");
	Customer *yuanzhen = new Customer("Yuanzhen Gu",4,80.00,"45 Kilmer Road, Edison","New Jersey","08817");
	Customer *zi = new Customer("Zi Yan",5,100.00,"100 Middlesex Essex Turnpike, Iselin","New Jersey","08830");


/*

	1) Insert the Customers into the database
	2) Create a few orders to try 
	3) Run the process function on them
	4) Print the accepted and rejected lists
*/

	database.insert(brian);
	database.insert(ying);
	database.insert(sejong);
	database.insert(yuanzhen);
	database.insert(zi);

	Order *one = new Order("I could pee on this",7.49,1,"housing");
	Order *two = new Order("Across Islands and Oceans",1.99,1,"sports");
	Order *three = new Order("Soul Surfer",7.99,3,"sports");
	Order *four = new Order("Immortal HELA",200000.00,4,"politics");

	
	process(one,database);
	process(two,database);
	process(three,database);
	process(four,database);


	cout << "\n\n\n";

	Customer *temp = database.find(1);
	cout << "The Accepted list for customer 1 is: \n";
	temp->printAccepted();
	cout << "\n\n";
	cout << "The Rejected list for customer 1 is: \n";
	temp->printRejected();
	cout << "\n\n";

	temp = database.find(2);
	cout << "The Accepted list for customer 2 is: \n";
	temp->printAccepted();
	cout << "\n\n";
	cout << "The Rejected list for customer 2 is: \n";
	temp->printRejected();
	cout << "\n\n";

	temp = database.find(3);
	cout << "The Accepted list for customer 3 is: \n";
	temp->printAccepted();
	cout << "\n\n";
	cout << "The Rejected list for customer 3 is: \n";
	temp->printRejected();
	cout << "\n\n";


	temp = database.find(4);
	cout << "The Accepted list for customer 4 is: \n";
	temp->printAccepted();
	cout << "\n\n";
	cout << "The Rejected list for customer 4 is: \n";
	temp->printRejected();
	cout << "\n\n";

	temp = database.find(5);
	cout << "The Accepted list for customer 5 is: \n";
	temp->printAccepted();
	cout << "\n\n";
	cout << "The Rejected list for customer 5 is: \n";
	temp->printRejected();
	cout << "\n\n";


	cout << "Customer info: ";
	brian->print();
	cout << "\n";

	cout << "Customer info: ";
	ying->print();
	cout << "\n";

	cout << "Customer info: ";
	sejong->print();
	cout << "\n";

	cout << "Customer info: ";
	yuanzhen->print();
	cout << "\n";

	cout << "Customer info: ";
	zi->print();
	cout << "\n";

	delete one;
	delete two;
	delete three;
	delete four;
	
	delete brian;
	delete ying;
	delete sejong;
	delete yuanzhen;
	delete zi;





































/*
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
*/
	

//	found->print();	

//	cout << "The size is: " << myList.getSize() << endl;
/*
	delete one;
	delete two;
	delete three;
	delete four;
	delete five;
*/	
	return 0;
}
	
