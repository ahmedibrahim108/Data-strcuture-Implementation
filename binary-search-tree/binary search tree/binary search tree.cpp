#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    //insert
    Node* insert(Node* r, int item) {
        if (r == nullptr) {
            return new Node(item);
        }
        else if (r->data > item) {
           r->left = insert(r->left, item);
        }
        else {
            r->right = insert(r->right, item);
        }
        return r;
    }

    void insert(int item) {
        root = insert(root, item);
    }

    //display
    void preorder(Node* r) { //root-left-right
        if (r == nullptr) {
            return;
        }
        cout << r->data << "\t";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node* r) { //left - root -right
        if (r == nullptr) {
            return;
        }
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }

    void postorder(Node* r) { //left - right - root
        if (r == nullptr) {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
    }

    //search
    Node* search(Node* r, int key) {
        if (r == nullptr) {
            return nullptr;
        }
        else if (r->data == key) {
            return r;
        }
        else if (key < r->data) {
            return search(r->left, key);
        }
        else {
            return search(r->right, key);
        }
    }

    bool search(int key) {
        Node* res = search(root, key);
        if (res == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    //find minmum
    Node* findmin(Node* r) {
        if (r == nullptr) {
            return NULL;
        }
        else if ( r->left == nullptr){
            return r;
        }
        else {
            findmin(r->left);
        }
    }

    //findmax
    Node* findmax(Node* r) {
        if (r == nullptr) {
            return NULL;
        }
        else if (r->right == nullptr) {
            return r;
        }
        else {
            findmax(r->right);
        }
    }


    //delete
    Node* Delete(Node* r, int key) {
        if (r == nullptr) {
            return NULL;
        }
        if (key < r->data) {
          r->left = Delete(r->left, key);
        }
        else if (key > r->data) {
          r->right = Delete(r->right, key);
        }
        else {
            if (r->left == nullptr && r->right == nullptr) { //leaf Node
                r = NULL;
            }
            else if (r->left != nullptr && r->right == nullptr) {
                r->data = r->left->data;
                delete r->left;
                r->left = nullptr;
          }
            else if (r->left == nullptr && r->right != nullptr) {
                r->data = r->right->data;
                delete r->right;
                r->right = nullptr;
            }
            else {
                Node* max = findmax(r->left);
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }
};
int main()
{
    BST b1;

    b1.insert(67);
    b1.insert(45);
    b1.insert(13);
    b1.insert(22);
    b1.insert(77);
    b1.insert(57);
    b1.insert(99);
    b1.insert(88);
    b1.insert(11);
    b1.insert(3);

    //display
    cout << "Showing the tree items" << endl;
    b1.preorder(b1.root);
    cout << "\n----------------------------------------" << endl;
   /* b1.inorder(b1.root);
    cout << "\n----------------------------------------" << endl;
    b1.postorder(b1.root);
    cout << "\n----------------------------------------" << endl;*/


    //search
   /* int x;
    cout << "Enter Item To search for" << endl;
    cin >> x;
    if (b1.search(x)) cout << "Item founded" << endl;
    else cout << "Item Not founded" << endl;*/

    //find minmum
  /*  cout << "The min item in the tree" << endl;
    Node* min = b1.findmin(b1.root);
    if (min == 0) {
        cout << "tree has no min items" << endl;
    }
    else {
        cout << "The min Item is " << min->data << endl;
    }*/

    //find maxmum
    //cout << "The max item in the tree" << endl;
    //Node* max = b1.findmax(b1.root);
    //if (max == 0) {
    //    cout << "tree has no max items" << endl;
    //}
    //else {
    //    cout << "The max Item is " << max->data << endl;
    //}

    //delete
    cout << "\nAfter Delete Items from tree\n";
    Node* res = b1.Delete(b1.root, 3);
    cout << "Tree after delete 3" << endl;
    b1.preorder(b1.root);

    res = b1.Delete(b1.root, 99);
    cout << "\nTree after delete 99" << endl;
    b1.preorder(b1.root);
}

