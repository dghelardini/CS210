//Names: Daelyn Ghelardini, Nicole Lawson, Natalia Sobery, Mia Walker
//Class: CS-210-01
//Homework Assignment #1
//Program 2

#include "myList.h"
#include <iostream>


int main()
{
	MyList obj;
	obj.showSOLL();

	obj.insert(1);
	obj.showSOLL();

	obj.insert(2);
	obj.showSOLL();

	obj.insert(3);
	obj.showSOLL();

	obj.insert(4);
	obj.showSOLL();

	obj.insert(4);
	obj.showSOLL();

	obj.insert(4);
	obj.showSOLL();

	obj.insert(5);
	obj.showSOLL();

	obj.removeBack();
	obj.showSOLL();

	obj.removeFront();
	obj.showSOLL();

	obj.removeItem(50); //Since delete is a keyword we renamed it removeItem
	obj.showSOLL();

	obj.moveToFront(3);
	obj.showSOLL();

	//system("pause");
	return 0;
	
}