#ifndef myList
#define myList
#include "List.h"


class MyList : List {
	struct Node {
		Node() : data{ -1 }, next{ nullptr } {};
		int data;
		Node *next;
	}; //this makes it private

public:

	MyList();
	MyList(const MyList &copy); //classname (const classname &obj) for copy constructor
	~MyList();



	//void isEmpty();
	void insert(int myData);
	void removeBack();
	void printList(); //don't copy virtual into this class
	void removeFront();
	void insertFront(const int &myData);
	void removeItem(const int &value);
	void insertAfter(const int &myData);
	void removeAll(const int &duplicate);
	int find(char value);
	void moveToFront(const int &value);
	void quickSort(int A[], int lower, int upper);
	MyList()
	{
		start = NULL;
	}

	//const int



private:
	bool remove(const int &value);
	bool isEmpty() const;
	Node *head; //must initialize to null
	Node *tail;
	Node *current;
};

#endif