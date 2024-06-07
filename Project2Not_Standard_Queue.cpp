#include <iostream>
#include "clsMyQueue.h"
using namespace std;

int main()
{
	clsMyQueue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);
	queue.push(60);


	cout << "Queue Items : \n\n";
	queue.print("\n\n");

	cout << "Queue size() : " << queue.size() << endl << endl;
	cout << "Queue front() : " << queue.front() << endl << endl;
	cout << "Queue back() : " << queue.back() << endl << endl;

	cout << "\nAfter Preform Queue pop() : \n";
	queue.pop();
	queue.print("\n\n");

	cout << "Queue getItem(3) : " << queue.getItem(3) << endl << endl;

	cout << "\nAfter Preform Queue reverse() : \n";
	queue.reverse();
	queue.print("\n\n");


	cout << "\nAfter Perfrom Queue updateItem(3) : \n";
	queue.updateItem(3, 1999);
	queue.print("\n\n");


	//This Has Nothing To Do With Standard Queue FIFO Data Structure.
	
	//cout << "\nAfter Perfrom Queue insertAfter() insert 950 After item 3 : \n";
	//queue.insertAfter(3, 950);
	//queue.print("\n\n");

	//cout << "\nAfter Perfrom Queue insertAtFront() insert 1000: \n";
	//queue.insertAtFront(1000);
	//queue.print("\n\n");

	//cout << "\nAfter Perfrom Queue insertAtBack() insert 3000: \n";
	//queue.insertAtBack(3000);
	//queue.print("\n\n");

	cout << "\nAfter Perfrom Queue clear() : \n";
	queue.clear();
	queue.print("\n\n");

	system("pause > 0");

	return 0;
}