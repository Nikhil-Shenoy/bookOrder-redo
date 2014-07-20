#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <string>
#include "order.h"

class OrderList
{
	public:
		OrderList();

		Order *find(int ID);
		void insert(Order *newOrder);
		void insert(const char *title, double price, int ID, const char *category);
		void remove(int ID);

		int getSize();

		void print();

		void setHead(Order *);
		Order *getHead();

	private:
		Order *head;
		int size;
};

#endif
