#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "../order/orderList.h"
#include "../order/order.h"
using namespace std;

class Customer 
{
	public:
		Customer(string Name, int custID, double credit, string Street, string State, string Zip);
		~Customer();

		void setName(string Name);
		string getName();
	
		void setID(int custID);
		int getID();
	
		void setCredit(double credit);
		double getCredit();

		void setStreet(string Street);
		string getStreet();

		void setState(string State);
		string getState();
	
		void setZip(string Zip);
		string getZip();

		void setNext(Customer *);
		Customer *getNext();

		void accept(Order *goodOrder);
		void reject(Order *badOrder);

		void printAccepted();
		void printRejected();

		void print();

	private:
		string name;
		int custID;
		double credit;
		string street;
		string state;
		string zip;
		
		OrderList accepted;
		OrderList rejected;
		
		Customer *next;

};

#endif
