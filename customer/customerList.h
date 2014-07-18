#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <string>
#include "customer.h"

class CustomerList
{
	public:
		CustomerList();

		Customer *find(int ID);
		void insert(Customer *newCustomer);
		void insert(string Name, int custID, double credit,string Street, string State, string Zip);
		void remove(int ID);

		int getSize();

		void print();

		void setHead(Customer *);
		Customer *getHead();

	private:
		Customer *head;
		int size;
};

#endif
