#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

   /* Node(int data) {
        this->data = data;
        this->next = nullptr;
    }*/
};

class Linkedlist {
public:

    Node* head;

    Linkedlist() {
        head = NULL;
    }

    // check the Node 
    bool isempty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }


    /*bool isempty() {
        return(head == NULL);
    }*/

    //insert first
    void insertfirst(int newvalue) {
        Node* newnode = new Node();
        newnode->data = newvalue;


        if (isempty()) {
            newnode->next = NULL;
            head = newnode;
        }
        else {
            newnode->next = head;
            head = newnode;
        }

    }

    //display
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }

    //count
    int count() {
        int counter = 0;
        Node* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    //search
    bool isfound(int item) {
        bool found = false;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == item) {
                found = true;
                break;
            }
            temp = temp->next;
        }
            return found;
    }

    //insert before
    void insertbefore(int item, int newvalue) {


        if (isfound(item)) {
            Node* newnode = new Node();
            newnode->data = newvalue;
            Node* temp = head;
            while (temp != NULL && temp->next->data != item ) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else {
            cout << "Sorry , Item Not found\n";
        }
    }

    //append add to the last of the list
    void append(int newvalue) {
        if (isempty()) {
            insertfirst(newvalue);
        }
        else {
            Node* temp;
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            Node* newnode = new Node();
            newnode->data = newvalue;

            temp->next = newnode;
            newnode->next = NULL;
        }
    }

    //delete
    void deleteItem(int item) {
        if (isempty()) {
            cout << "the list is empty \n";
            return;
        }

        if (isfound(item)) {

        Node* delptr;
        if (item == head->data) {
            delptr = head;
            head = head->next;
            delete delptr;
        }
        else {
            Node* prev = NULL;
            delptr = head;

            while (delptr->data != item) {
                prev = delptr;
                delptr = delptr->next;
            }

            prev->next = delptr->next;
            delete delptr;
        }
      }
    }
};


int main()
{
    Linkedlist list;

    // is empty & count
    if (list.isempty()) {
        cout << "List Is Empty" << endl;
    }
    else {
        cout << "the list contains: " << list.count() << endl;
    }

    // insert
    int x;
    cout << "Enter item to insert in the list \n";
    cin >> x;
    list.insertfirst(x);
    list.display();

    cout << "Enter item to insert in the list \n";
    cin >> x;
    list.insertfirst(x);
    list.display();

    cout << "Enter item to insert in the list \n";
    cin >> x;
    list.insertfirst(x);
    list.display();

    cout << "the list contains: " << list.count() << endl;

    //search
    cout << "Enter Item to search for \n";
    cin >> x;
    if (list.isfound(x)) {
        cout << "Item founded \n";
    }
    else {
        cout << "Item Not founded \n";
    }

    //insert before
    int item;
    cout << "Please Enter item and value you wan to insert \n";
    cin >> item >> x ;
    list.insertbefore(item, x);
    list.display();


    //append
    cout << "Please Enter the Value u wan to append?\n";
    cin >> x;
    list.append(x);
    list.display();

    //delete
    cout << "Please Enter the Item U wan to delet \n";
    cin >> x;
    list.deleteItem(x);
    list.display();


}
