#include <iostream>
#include <string>
#include "order.h"
#include "orderList.h"
using namespace std;

OrderList::OrderList()
	:head(NULL), size(0)
{
	head = NULL;
	size = 0;
	cout << endl;
}

Order *OrderList::find(int ID)
{
	Order *query = head;

	while(query->getID() != ID)
		query = query->getNext();

	if(query == NULL)
		return NULL;
	else
		return query;
}

void OrderList::insert(const char * title, double price, int ID, const char *category)
{	
	Order *newOrder = new Order(title,price,ID,category);

	Order *lead = head;
	Order *tail = NULL;

	if(head == NULL)
	{
		head = newOrder;
		newOrder->setNext(NULL);
		size++;
		return;
	}

	while((lead != NULL) && (newOrder->getID() >= lead->getID()))
	{
		tail = lead;
		lead = lead->getNext();
	}

	if(tail == NULL) // we haven't moved
	{
		newOrder->setNext(lead);
		head = newOrder;
		size++;
		return;
	}
	else if(lead == NULL) // end of the list
	{
		tail->setNext(newOrder);
		newOrder->setNext(NULL);
		size++;
		return;
	}
	else
	{
		newOrder->setNext(lead);
		tail->setNext(newOrder);
		size++;
		return;
	}
}


void OrderList::insert(Order *newOrder)
{

	Order *lead = head;
	Order *tail = NULL;

	if(head == NULL)
	{
		head = newOrder;
		newOrder->setNext(NULL);
		size++;
		return;
	}

	while((lead != NULL) && (newOrder->getID() >= lead->getID()))
	{
		tail = lead;
		lead = lead->getNext();
	}

	if(tail == NULL) // we haven't moved
	{
		newOrder->setNext(lead);
		head = newOrder;
		size++;
		return;
	}
	else if(lead == NULL) // end of the list
	{
		tail->setNext(newOrder);
		newOrder->setNext(NULL);
		size++;
		return;
	}
	else
	{
		newOrder->setNext(lead);
		tail->setNext(newOrder);
		size++;
		return;
	}

	
}
	
void OrderList::print()
{
	Order *temp = head;

	while(temp != NULL)
	{
		temp->print();	
		temp = temp->getNext();
	}
}

int OrderList::getSize()
{
	return size;
}

void OrderList::setHead(Order *newHead)
{
	head = newHead;
}

Order *OrderList::getHead()
{
	return head;
}


void OrderList::remove(int ID)
{
	Order *lead = this->getHead();
	Order *tail = NULL;
	if(lead == NULL) {
		cout << "List is empty.\n";
		return;
	}

	while(lead->getID() != ID) {
		tail = lead;
		lead = lead->getNext();
	}

	if(tail == NULL) { // means that lead is pointing to head
		this->setHead(lead->getNext());
		lead->setNext(NULL);
		delete lead;
		return;
	}
	else if(lead == NULL) { // element not found in the list	
		cout << "Element to be removed was not found in the list\n";
		return;
	}
	else {
		tail->setNext(lead->getNext());
		lead->setNext(NULL);
		delete lead;
		return;
	}
}	
