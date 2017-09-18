// ListProcessor.cpp
// Edited by McKade Umbenhower

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl;
	cout << "cows list length: " << cows.size() << endl;
	cout << "cows list sum: " << cows.sum() << endl << endl;

	cows.insertAsLast(1.00);
	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cows.insertAsLast(2.01);
	cout << "cows list  :  " << cows << endl;
	cout << "cows list length: " << cows.size() << endl;
	cout << "cows list sum: " << cows.sum() << endl << endl;

	cows.removeFirst();
	cows.insertAsLast(3.00);
	cows.removeFirst();
	cout << "cows list  :  " << cows << endl;
	cout << "cows list length: " << cows.size() << endl;
	cout << "cows list sum: " << cows.sum() << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "horses list length: " << horses.size() << endl;
	cout << "horses list sum: " << horses.sum() << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	horses.insertAsLast(2.09);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "End of code" << endl;

	return 0;
}
