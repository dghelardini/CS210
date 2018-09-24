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
	printList();
	while (head != nullptr) {
		removeBack();
	}
	printList();
}

void MyList::printList()
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
int myList::find(char value)
{

	int pos = 0;
	bool flag = false;
	if (head == NULL)
	{
		return 0;
	}
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{
		pos++;
		if (temp->data == value)
		{
			flag = true;
			return pos;
		}
		temp = temp->next;
	}
	if (!flag)
		return 0;
}

void MyList::move_to_front()
{
	if (head == NULL)
	{
		std::cout << "The List is Empty, first create the list" << std::endl;
		return;
	}
	char stream[100001];
	std::cout << "Enter the string of elements searched" << std::endl;
	std::cin >> stream;
	int m, n;
	m = strlen(stream);
	for (int i = 0; i < m; i++)
	{
		if (find(stream[i]) != 0)
		{
			if (find(stream[i]) != 1)
			{
				n = find(stream[i]);
				remove(n);
				insertFront(stream[i]);
			}
			std::cout << stream[i] << ": ";
			printList();
		}
	}
}

void MyList::sort()
{
	int value, temp;
	if (head == NULL)
	{
		return;
	}
	nullptr = head;
	while (nullptr != NULL)
	{
		for (s = nullptr->next; s != NULL; s = s->next)
		{
			if (nullptr->counter < s->counter)
			{
				value = nullptr->info;
				temp = nullptr->counter;
				nullptr->info = s->info;
				nullptr->counter = s->counter;
				s->info = value;
				s->counter = temp;
			}
		}
		nullptr = ptr->next;
	}
}