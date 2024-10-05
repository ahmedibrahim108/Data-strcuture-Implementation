#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Stack {
	Node* top;

public:
	Stack() {
		top = nullptr;
	}

	//check stack if is empty
	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	// puch on th stack
	void push(int item) {

		//creating new node
		Node* newnode = new Node();
		newnode->data = item;

		//check if the stack is empty or not
		if (isEmpty()) {
			newnode->next = nullptr;
			top = newnode;
		}
		else {
			newnode->next = top;
			top = newnode;
		}
	}

	// display elemnts on the stack
	void display() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	//removing item from the stack
	int pop() {
		int value;
		value = top->data;
		Node* delptr = top;

		top = top->next;
		delete delptr;
		return value;
	}

	//return the value od top element

	int peek() {
		return top->data;
	}

	//return stack count 

	int counter() {
		int counter = 0;
		Node* temp = top;
		while (temp != nullptr) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	//check exastance of item
	bool isFound(int item) {
		bool found = false;
		Node* temp = top;
		while (temp != nullptr) {
			if (temp->data == item) {
				found = true;
		  }
			temp = temp->next;
		}

		return found;
	}
};

int main()
{
	Stack s1;
	int x;

	for (int i = 0; i < 5; i++) {
		cout << "Enter Your Item" << endl;
		cin >> x;
		s1.push(x);
		s1.display();
	}

	cout << s1.pop() << "was deleted from the stack" << endl;
	s1.display();

	cout << s1.pop() << "was deleted from the stack" << endl;
	s1.display();
   
}

