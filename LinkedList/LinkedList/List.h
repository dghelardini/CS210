//Names: Daelyn Ghelardini, Nicole Lawson, Natalia Sobery, Mia Walker
//Class: CS-210-01
//Homework Assignment #1
//Program 2

#ifndef List_h
#define List_h

class List {
public:
	virtual void showSOLL() = 0;
	//virtual void printReverse() =0;
	//virtual void insertFirst(init) =0;
	//virtual void insertLast(int) = 0;
	//virtual void deleteNode(int) = 0;
	virtual void removeAll(const int &duplicate) = 0; //parent class
};

#endif
