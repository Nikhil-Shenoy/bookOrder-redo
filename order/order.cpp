#include <iostream>
#include <string>
#include "order.h"
using namespace std;

Order::Order(const char *Title, double Price, int myID, const char *Category)
{
	title = Title;
	price = Price;
	ID = myID;
	category = Category;

	next = NULL;
}

void Order::setTitle(const char *newTitle)
{
	title = newTitle;
}

string Order::getTitle()
{
	return title;
}

void Order::setPrice(double newPrice)
{
	price = newPrice;
}

double Order::getPrice()
{
	return price;
}

void Order::setID(int newID)
{
	ID = newID;
}

int Order::getID()
{
	return ID;
}

void Order::setCategory(const char *newCategory)
{
	category = newCategory;
}

string Order::getCategory()
{
	return category;
}

void Order::setNext(Order *newNext)
{
	next = newNext;
}

Order *Order::getNext()
{
	return next;
}	
