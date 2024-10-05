#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		this->data = 0;
		this->next = nullptr;
	}
};

class Queue {
public:
	Node* front;
	Node* rear;

	Queue() {
		front = rear = nullptr;
	}

	// check if the queue is empty
	bool isEmpty() {
		if (front == nullptr && rear == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	//adding items to the queue
	void enqueue(int item) {
		Node* newnode = new Node();
		newnode->data = item;

		if (isEmpty()) {
			front = newnode;
			rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}

	}

	//travrse all items in the queue
	void display() {
		if (isEmpty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			Node* temp = front;

			while (temp != nullptr) {
				cout << temp->data << "\t ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	//removing items from the queue
	int dequeue() {
		int delvalue = -1;
		if (isEmpty()) {
			cout << "the queue is empty" << endl;
		}
		else if (front == rear) {
			delete front;
			front = rear = nullptr;
		}
		else {
			Node* delptr;
			delptr = front;
			front = front->next;
			delvalue = delptr->data;
			delete delptr;
		}
		return delvalue;
	}

	//get the front
	int getfront() {
		return front->data;
	}

	//get the rear
	int getrear() {
		return rear->data;
	}

	//count 
	int count() {
		int counter = 0;
		Node* temp = front;
		if (isEmpty()) {
			cout << "The queue is epmty" << endl;
		}
		else {
			while (temp != nullptr) {
				temp = temp->next;
				counter++;
			}
			cout << endl;
		}
		return counter;
	}

	//search
	bool search(int item) {
		bool found = false;

		if (isEmpty()) {
			cout << "The queue is empty" << endl;
		}
		else {
			Node* temp = front;
			while (temp != nullptr) {
				if (temp->data == item) {
					found = true;
				}
				temp = temp->next;
			}
		}
		return found;
	}

	//clear
	void clear() {
		while (!isEmpty()) {
			dequeue();
		}
	}
};


int main()
{
	Queue q1;

	cout << "Queue Implementation" << endl;

	//Enqueue
	int item;
	for (int i = 0; i < 5; i++) {
		cout << "Please Enter the item" << endl;
		cin >> item;
		q1.enqueue(item);
	}

	//display
	q1.display();
	cout << "Count of the queue" << q1.count();

	//search

	cout << "Please Enter iteam to search" << endl;
	cin >> item;
	if (q1.search(item))
		cout << "The item is in the queue" << endl;
	else
		cout << "The Item Not Founded" << endl;


	//dequeue
	/*cout << "After Dequeue \n";
	q1.dequeue();
	q1.display();

	q1.dequeue();
	q1.display();

	q1.dequeue();
	q1.display();
	cout << "Count of the queue" << q1.count();*/


	//clear
	cout << "After clearing the queue" << endl;
	q1.clear();
	cout << "Display after the clear" << endl;
	q1.display();

}
