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
using namespace std;
using namespace boost;


void *prodFunct(void *argument)
{
	cout << "hello from thread" << endl;
	string myArg = *((string *)argument);
	
	cout << "Hello from the prodFunct function!";
	cout << " The argument is " << myArg;

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


	char *categories[catCount];


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


	string arg("Vineet Shenoy");
	string *ptr = &arg;

	int returnValue;

	cout << "creating thread\n";	
	returnValue = pthread_create(&producer, NULL, prodFunct, (void *)ptr);	

	pthread_join(producer, NULL);
	cout << "The returnValue is: " << returnValue << endl;

	return 0;
}	

