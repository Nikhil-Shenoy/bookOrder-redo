#include <iostream>
#include <string>
#include <fstream> // used to read from and write to files
#include <ios>
#include <cstring>
#include <cstdlib>
#include <pthread.h>
#include <boost/tokenizer.hpp>
#include "customer/customer.h"
#include "customer/customerList.h"
#include "order/order.h"
using namespace std;
using namespace boost;

Order *buffer[10];


void *prodFunct(void *argument)
{
	cout << "The result is: " << *((string *)argument) << endl;

	FILE *orderFile = fopen("orders.txt","r");

	char temp[251];

	while(fgets(temp,250,orderFile))
	{

		char *title = strtok(temp,"|");
		char *price = strtok(NULL,"|");
		char *ID = strtok(NULL,"|");
		char *category = strtok(NULL,"|");

		Order *newOrder = new Order(title,atof(price),atoi(ID),category);
		cout << "\n\n";
		newOrder->print();
		cout << "\n\n";


		delete newOrder;
/*
		newOrder->print();
		
		delete newOrder;
		*/
	
	}
	
	
	fclose(orderFile);

}

int main(int argc, char **argv)
{
	CustomerList database;


	char *db;
	char *order;
	char *cat;

	db = argv[1];
	order = argv[2];
	cat = argv[3];

	FILE *catFile = fopen(cat,"r");


	int catCount = 0; // number of categories in the file
	char temp[100];
	while(fgets(temp,100,catFile))
		catCount++;

	rewind(catFile);


/*
	if(catFile.ios::eof())
		cout << "EOF bit is set" << endl;
	if(catFile.ios::fail())
		cout << "failbit is set" << endl;
*/


	string categories[catCount];


	catCount = 0;
	while(fgets(temp,100,catFile))
	{
		categories[catCount] = temp;
		catCount++;
	}

	// now we have an array of the categories	
	

	FILE *dbFile = fopen(db,"r");

	char stringBuf[100];
	
	while(fgets(stringBuf,100,dbFile))
	{

		string name(strtok(stringBuf,"|"));
		int custID = atoi(strtok(NULL,"|"));
		double credit = atof(strtok(NULL,"|"));	
		string street(strtok(NULL,"|"));	
		string state(strtok(NULL,"|"));
		string zip(strtok(NULL,"|"));	


		Customer *newEntry = new Customer(name,custID,credit,street,state,zip);

		database.insert(newEntry);	
	}	


	database.print();	
	
	// created the customer database

	// create the producer thread and consumer threads

	pthread_t producer;
	pthread_t consumer;


	cout << "creating thread\n";	
	pthread_create(&producer, NULL, prodFunct, (void *)&categories[1]);	

	int status;
	status = pthread_join(producer, NULL);

	cout << "Status is: " << status << endl;
	return 0;
}	

