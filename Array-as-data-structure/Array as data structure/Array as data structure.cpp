#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int lenght;
    int* items;

public:
    // creation
    Array(int arrsize) {
        size = arrsize;
        lenght = 0;
        items = new int[arrsize];
    }

    // filling
    void filling() {
        int no_of_items;
        cout << "Please Enter The Number of items \n";
        cin >> no_of_items;
        if (no_of_items > size) {
            cout << "You can't exceesed array size \n";
            return;
        }
        else {
            for (int i = 0; i < no_of_items; i++) {
                cout << "Enter item n  " << i << endl;
                cin >> items[i];
                lenght++;
            }
        }
    }

    //didplay
    void Display() {
        cout << "Your Array Content" << endl;
        for (int i = 0; i < lenght; i++) {
            cout << items[i] << '\t';
        }
        cout << endl;
    }

    // Get Size
    int getSize() {
        return size;
    }
    // Get Lenght
    int getLenght() {
        return lenght;
    }

    //search
    int search(int key) {
        int index = -1;

        for (int i = 0; i < lenght; i++) {
            if (items[i] == key) {
                index = i;
                break;
            }
        }
        return index;
    }

    //append
    void append(int newItem) {
        if (lenght < size) {
            items[lenght] = newItem;
            lenght++;
        }
        else {
            cout << "Array is full" << endl;
        }
    }

    //insert
    void insert(int index,int newItem) {
        if (index > 0 && index < size) {
            for (int i = lenght; i > index; i--) {
                items[i] = items[i - 1];
            }
            items[index] = newItem;
            lenght++;
        }
        else {
            cout << "Error found " << endl;
        }
    }

    //delete
    void deleteIndex(int index) {
        if (index > 0 && index < size) {
            for (int i = index; i < lenght - 1; i++) {
                items[i] = items[i + 1];
            }
            lenght--;
        }
    }

    //enlarge
    void enlarge(int newsize) {
        if (newsize <= size) {
            cout << "you must enter size more the original one \n";
            return;
        }
        else {
            size = newsize;
            int* temp = items;
            items = new int[newsize];

            for (int i = 0; i < lenght; i++) {
                items[i] = temp[i];
            }
            delete[] temp;
        }
    }

    //merge
    void merge(Array others) {

        int newsize = size + others.getSize();
        size = newsize;
        int* temp = items;
        items = new int[newsize];
      

        int i ;
        for (i = 0; i < lenght; i++) {
            items[i] = temp[i];
        }
        delete[] temp;
        int j = i;
        for (int i = 0; i < others.getLenght();i++){
            items[j++] = others.items[i];
            lenght++;
        }
    }
};
int main()
{
    cout << "Hello Array As ADT  " << endl;
    int arraysize;
    cout << "Please Enter Array size\n";
    cin >> arraysize;

    Array myArray(arraysize);
    myArray.filling();
    cout << "Array Size = " << myArray.getSize() << " While lenght = " << myArray.getLenght() << endl;
    myArray.Display();

    //search
   /* int key ;
    cout << "Please Enter Your Item U wa to search \n";
    cin >> key;
    int index = myArray.search(key);
    if (index == -1) {
        cout << "The Item You enterd not found" << endl;
    }
    else {
        cout << "The item u entered is found @ position " << index << endl;
    }*/

    //append
 /*   int newItem;
    cout << "enter new item" << endl;
    cin >> newItem;
    myArray.append(newItem);
    myArray.Display();*/
   
    //insert 
   /* cout << " Enter item u wa to insert \n";
    cin >> newItem;
    cout << " Enter item index wa to insert \n";
    cin >> index;

    myArray.insert(index, newItem);
    myArray.Display();*/


    //delete
 /*   cout << "enter index" << endl;
    cin >> index;
    myArray.deleteIndex(index);
    cout << "Array Size = " << myArray.getSize() << " While lenght = " << myArray.getLenght() << endl;
    myArray.Display();*/

    //enlarge
   /* int newsize;
    cout << "please enter new size \n";
    cin >> newsize;
    myArray.enlarge(newsize);
    cout << "Array Size = " << myArray.getSize() << " While lenght = " << myArray.getLenght() << endl;
    myArray.Display();*/

    //merge
    Array others(3);
    others.filling();
    myArray.merge(others);
    /*cout << "Array Size = " << myArray.getSize() << " While lenght = " << myArray.getLenght() << endl;*/
    myArray.Display();
}

