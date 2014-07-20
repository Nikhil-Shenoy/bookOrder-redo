#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;


class Order {
	
	public:
		Order(const char *title, double price, int ID, const char *category);

		void setTitle(const char *newTitle);
		string getTitle();

		void setPrice(double newPrice);
		double getPrice();

		void setID(int newID);
		int getID();

		void setCategory(const char *newCategory);
		string getCategory();

		void setNext(Order *newNext);
		Order *getNext();

		void print();

	private:
		string title;
		double price;
		int ID;
		string category;

		Order *next;
};

#endif
