#ifndef List_h
#define List_h

class List {
public:
	virtual void printList() = 0;
	//virtual void printReverse() =0;
	//virtual void insertFirst(init) =0;
	//virtual void insertLast(int) = 0;
	//virtual void deleteNode(int) = 0;
	virtual void removeAll(const int &duplicate) = 0; //parent class
};

#endif
