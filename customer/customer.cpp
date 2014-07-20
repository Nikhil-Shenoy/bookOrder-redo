#include <iostream>
#include <string>
#include "customer.h"
#include "../order/order.h"
using namespace std;

Customer::Customer(string Name, int ID, double Credit, string Street, string State, string Zip)
{
	name = Name;
	custID = ID;
	credit = Credit;
	street = Street;
	state = State;
	zip = Zip;
	next = NULL;
}

Customer::~Customer()
{
	cout << "The Destructor was called" << endl;
}


void Customer::setName(string Name)
{
	name = Name;
}

string Customer::getName()
{
	return name;
}

void Customer::setID(int ID)
{
	custID = ID;
}

int Customer::getID()
{
	return custID;
}

void Customer::setCredit(double Credit)
{
	credit = Credit;
}

double Customer::getCredit()
{
	return credit;
}

void Customer::setStreet(string Street)
{
	street = Street;
}

string Customer::getStreet()
{
	return street;
}

void Customer::setState(string State)
{
	state = State;
}

string Customer::getState()
{
	return state;
}

void Customer::setZip(string Zip)
{
	zip = Zip;
}

string Customer::getZip()
{
	return zip;
}
void Customer::setNext(Customer *newNext)
{
	next = newNext;
}

Customer *Customer::getNext()
{
	return next;
}

void Customer::accept(Order *goodOrder)
{
	this->accepted.insert(goodOrder);
	return;
}

void Customer::reject(Order *badOrder)
{	
	rejected.insert(badOrder);
	return;
}

void Customer::printAccepted()
{
	accepted.print();
	return;
}

void Customer::printRejected()
{
	rejected.print();
	return;
}

void Customer::print()
{
	cout << "Name: " << name << endl;
	cout << "ID: " << custID << endl;
	cout << "Credit: $" << credit << endl;
	cout << "Street: " << street << endl;
	cout << "State: " << state << endl;
	cout << "Zip: " << zip << endl;
	cout << "\n\n";
}
















