#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
using namespace std;



int main()
{


	Customer *nikhil = new Customer("Nikhil",1,100.0,"a","b","c");

	Customer *sample = nikhil;
	vector<Customer *> save;

	save.push_back(nikhil);

//	foo();

//	sup.print();
	save[0]->print();

	delete sample;
//	delete save[0];	

	return 0;
}	
