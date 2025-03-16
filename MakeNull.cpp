#include <iostream>
using namespace std;

// DOUBLY LINKED LIST (where each element points to the next and previous element in the list)
typedef int ElementType;
class node {
public:
    ElementType data;
    node* next;
    node* prev;
};
typedef node* pos;

class DoublyList {
private:
    pos head = nullptr;
    pos tail = nullptr;
    int counter = 0;
public:
    void MakeNull();
    void InsertAtEnd(ElementType x);
    void InsertAtStart(ElementType x);
    void insert(ElementType x, pos p);
    void printList();
};

void DoublyList::InsertAtStart(ElementType x) {
    pos newNode = new node;
    newNode->data = x;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
    counter++;
}

void DoublyList::InsertAtEnd(ElementType x) {
    pos newNode = new node;
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = tail;  // Corrected: prev should point to tail, not head

    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = tail;
    }
    counter++;
}

void DoublyList::insert(ElementType x, pos p) {
    if (p == nullptr) {
        InsertAtEnd(x);
    }
    else if (p == head) {
        InsertAtStart(x);
    }
    else {
        pos newNode = new node;
        newNode->data = x;
        newNode->prev = p->prev;
        newNode->next = p;

        if (p->prev != nullptr) {
            p->prev->next = newNode;
        }

        p->prev = newNode;
        counter++;
    }
}

void DoublyList::MakeNull() {
    while (head != nullptr) {
        pos temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    counter = 0;
}

void DoublyList::printList() {
    pos current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    DoublyList list;
    pos p = nullptr;

    // Insert some elements into the list
    list.insert(10, p);
    list.insert(20, p);
    list.insert(30, p);

    // Print the list to verify its contents
    cout << "List before MakeNull: ";
    list.printList();

    // Call MakeNull to delete all nodes
    list.MakeNull();

    // Print the list again to verify it's empty
    cout << "List after MakeNull: ";
    list.printList();

    return 0;
}