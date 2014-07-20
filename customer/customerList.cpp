#include <iostream>
#include <string>
#include "customer.h"
#include "customerList.h"
using namespace std;

CustomerList::CustomerList()
	:head(NULL), size(0)
{
	head = NULL;
	size = 0;
	cout << endl;
}

Customer *CustomerList::find(int ID)
{
	Customer *query = head;

	while(query->getID() != ID)
		query = query->getNext();

	if(query == NULL)
		return NULL;
	else
		return query;
}

void CustomerList::insert(string Name, int custID, double credit, string Street, string State, string Zip)
{	
	Customer *newCustomer = new Customer(Name, custID, credit,Street,State,Zip);

	Customer *lead = head;
	Customer *tail = NULL;

	if(head == NULL)
	{
		head = newCustomer;
		newCustomer->setNext(NULL);
		size++;
		return;
	}

	while((lead != NULL) && (newCustomer->getID() >= lead->getID()))
	{
		tail = lead;
		lead = lead->getNext();
	}

	if(tail == NULL) // we haven't moved
	{
		newCustomer->setNext(lead);
		head = newCustomer;
		size++;
		return;
	}
	else if(lead == NULL) // end of the list
	{
		tail->setNext(newCustomer);
		newCustomer->setNext(NULL);
		size++;
		return;
	}
	else
	{
		newCustomer->setNext(lead);
		tail->setNext(newCustomer);
		size++;
		return;
	}
}


void CustomerList::insert(Customer *newCustomer)
{

	Customer *lead = head;
	Customer *tail = NULL;

	if(head == NULL)
	{
		head = newCustomer;
		newCustomer->setNext(NULL);
		size++;
		return;
	}

	while((lead != NULL) && (newCustomer->getID() >= lead->getID()))
	{
		tail = lead;
		lead = lead->getNext();
	}

	if(tail == NULL) // we haven't moved
	{
		newCustomer->setNext(lead);
		head = newCustomer;
		size++;
		return;
	}
	else if(lead == NULL) // end of the list
	{
		tail->setNext(newCustomer);
		newCustomer->setNext(NULL);
		size++;
		return;
	}
	else
	{
		newCustomer->setNext(lead);
		tail->setNext(newCustomer);
		size++;
		return;
	}

	
}
	
void CustomerList::print()
{
	Customer *temp = head;

	while(temp != NULL)
	{
		temp->print();	
		temp = temp->getNext();
	}
}

int CustomerList::getSize()
{
	return size;
}

void CustomerList::setHead(Customer *newHead)
{
	head = newHead;
}

Customer *CustomerList::getHead()
{
	return head;
}


void CustomerList::remove(int ID)
{
	Customer *lead = this->getHead();
	Customer *tail = NULL;
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
