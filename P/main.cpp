
#include "myList.hpp"
#include <iostream>


int main()
{
	MyList obj;
	obj.printList();
	
	obj.insert(1);
	obj.printList();

	obj.insert(2);
	obj.printList();

	obj.insert(3);
	obj.printList();

	obj.insert(4);
	obj.printList();

	obj.insert(4);
	obj.printList();

	obj.insert(4);
	obj.printList();

	obj.insert(5);
	obj.printList();

	//obj.removeBack();
	//obj.printList();
	
	//obj.removeFront();
	//obj.printList();

	obj.removeItem(50);
	obj.printList();

	

	system("pause");
	return 0;
}

