//Names: Daelyn Ghelardini, Nicole Lawson, Natalia Sobery, Mia Walker
//Class: CS-210-01
//Homework Assignment #1
//Program 2

#include <iostream>
#include "myList.h"
#include <stdexcept>



MyList::MyList()
{
	head = nullptr; //initializing all to null
	tail = nullptr;
	current = nullptr;
}

MyList::MyList(const MyList & copy)
{

}

MyList::~MyList()
{
	std::cout << "Destroying the items:" << std::endl;
	showSOLL();
	while (head != nullptr) {
		removeBack();
	}
	showSOLL();
}

void MyList::showSOLL()
{
	if (isEmpty()) { //head == nullptr;
		std::cout << "List is empty." << std::endl;
	}
	else if (head->next == nullptr) {
		std::cout << head->data << std::endl; //printing the data.
	}
	else {
		current = head;
		while (current->next != nullptr) {

			std::cout << current->data << ",";
			current = current->next;
		}

		std::cout << current->data << std::endl;
	}

	current = nullptr; //what you do when there is no next.  So we must reset to null
}

void MyList::removeFront()
{ //3 cases
  //none
	if (isEmpty()) { //head == nullptr
		std::cout << "List is empty.  Can't remove anything." << std::endl;
	}

	else if (head->next == nullptr) {//there is one item
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	else { //when there are multiple items
		current = head;
		head = head->next;

		delete current;
		current = nullptr;
	}
}

void MyList::insertFront(const int &myData)

{ //when there is no front yet.  Need to make one.
	Node *temp = new Node;
	temp->data = myData;
	if (isEmpty()) { // head == nullptr
		std::cout << "List is moving head to point to tmp" << std::endl;
		head = temp;
		tail = temp;
	}
	//when there is another item at the front
	else if (head->next == nullptr) {
		temp->next = head;
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	temp = nullptr;
}

void MyList::removeItem(const int &value)
{	//remove middle item
	//compare to see if data is in the list
	Node *current = nullptr;
	Node *previous = nullptr;
	current = head;
	while (current->data != value) {
		previous = current;
		current = current->next;
		//this loop stops at the value we are looking for.

		//need to take into account when you hit the end and the item isn't there.
		if (tail == previous) {
			throw std::invalid_argument("Number is not in the list.");
			//https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception

		}
	}

	//see if the user gave us a number in the list, but there's no number after that one.
	if (current == nullptr) {
		throw std::invalid_argument("No number after inputted number to remove.");
	}
	previous->next = current->next; //setting the previous one so it skips over one to remove.
	delete current;
	current = nullptr;

	//set the node so that you are at the one before the one to remove.
	//have that node's next point to the one after the one to remove.
	//now remove/delete the middle node with the value you want.

}


void MyList::insertAfter(const int &myData)
{
	Node *temp = new Node;
	temp->data = myData;

	//empty
	if (isEmpty()) { //head == nullptr
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	else if (head->next == nullptr) { //if the head is the only item in list (both cases)
		if (head->data < temp->data) //when data inserted is bigger than head
		{
			head->next = temp;
			tail = temp;
			temp = nullptr;

		}
		else { //item is smaller than the head
			head = temp;
			temp->next = tail;
			temp = nullptr;
		}

	}
	else {
		if (temp->data < head->data) { //if my item is inserted in a list with at least 2 items. insert before head
			temp->next = head;
			head = temp;
			temp = nullptr;
			return;	//the lower if won't happen if this is the case
		}
		if (tail->data < temp->data) {//insert at the end.
			tail->next = temp;
			tail = temp;
			temp = nullptr;
		}
		else { //going in the middle
			current = head;
			while (current->next->data < temp->data) { //compare the current next's data to what the temp data is.
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
			temp = nullptr;

		}

	}
}

void MyList::removeAll(const int &duplicate)
{
	while (remove(duplicate)) {
		std::cout << "Removing the duplicate: " << duplicate << std::endl;
	}
}

bool MyList::remove(const int &value)
{

	if (isEmpty()) {
		std::cout << "Remove(): List is empty";
		return false;
	}
	else if (head->next == nullptr) { //only head in the list, and value matches head.
		if (head->data == value) {

			delete head;
			current = nullptr;
			head = nullptr;
			tail = nullptr;

			return true;
		}
		return false;
	}
	else {
		if (head->data == value) {
			current = head;
			head = head->next;
			delete current;
			current = nullptr;
			return true;
		}
		else {
			current = head;
			Node *previous = nullptr;
			while ((current->data != value) && (current->next != nullptr)) {
				previous = current;
				current = current->next;

			}

			if (current->data == value) {
				tail = previous;

			}

			previous->next = current->next;
			delete current;
			current = nullptr;
			previous = nullptr;
			return true;

		}
		return false;
	}
}


bool MyList::isEmpty() const {
	if (head == nullptr)
		return true;
	else {
		return false;
	}
}

void MyList::insert(int myData)
{	//if the list is empty (check if head is null)
	//if the list has only one object ( when is isn't null, then check head.next() == null)
	//more than one item (this is the else case)

	current = head;

	Node *temp = new Node;
	temp->data = myData; //putting your data into the temporary node

						 //temp->next = nullptr; //initilize.  Must do this for each node.  You can also make it part of the node struct

	if (isEmpty()) { //head == nullptr
		std::cout << "List is empty moving head to point to temp" << std::endl;
		head = temp; //starting the list
	}
	else if (head->next == nullptr) { //when you just have the head
		tail->next = temp;

	}

	else {
		//while (current ->next != nullptr) {
		//	current = current->next; 
		//}
		//current->next = temp;
		tail->next = temp;
	}
	tail = temp; //or you could write this outside the last else bracket, because you do the same for the 3 brackets
}

void MyList::removeBack()
{
	current = head;

	if (isEmpty()) { //head == nullptr
		std::cout << "RemoveBack: List Empty" << std::endl;
	}
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		while (current->next != tail) {
			current = current->next; //increment the current
		}
		delete current->next;
		current->next = nullptr;
		tail = current;
		current = nullptr;

	}

}

int MyList::find(const int &myData)
{
	Node *temp = new Node;
	temp->data = myData;

	int pos = 0;
	bool flag = false;

	if (head == nullptr)
	{
		return 0;
	}

	temp = head;
	while (temp != NULL)
	{
		pos++;
		if (temp->data == myData)
		{
			flag = true;
			return pos;
		}
		temp = temp->next;
	}
	if (!flag)
		return 0;
}

void MyList::moveToFront(const int &value)
{
	Node *previous = head;
	current = head;

	if (head == NULL)
	{
		std::cout << "The List is Empty, first create the list" << std::endl;
		return;
	}
	
	//search the list
	while(current->data != value && current->next != nullptr)
	{
		if (current->next == nullptr)
		{
			std::cout << "The list does not contain that item" << std::endl;
		}
		else if (current->data == value)
		{
			//set the previous node's next to the current's next 
			previous->next = current->next;
			//set the current's next to the head
			current->next = head;
			//update head
			head = current;
		}
		else
		{
			//go to next node
			current = current->next;
		}
	}
	current = nullptr;
	previous = nullptr;
}

void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int findPartition(int list[], int lower, int upper)
{
	int var = list[upper];
	int index = (lower - 1);

	for (int j = lower; j <= upper - 1; j++)
	{
		if (list[j] <= var)
		{
			index++;
			swap(&list[index], &list[j]);
		}
	}
	swap(&list[index + 1], &list[upper]);
	return (index + 1);
}

void MyList::quickSort(int A[], int lower, int upper)
{
	if (lower < upper)
	{
		//find the partition and sort each half recursively
		int partition = findPartition(A, lower, upper);
		quickSort(A, lower, partition - 1);
		quickSort(A, partition + 1, upper);
	}

}
