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
    // Insert function to add elements in ascending order
    void insert(ElementType x) {
        pos newNode = new node;
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (counter == 0) {
            // If the list is empty, insert the new node as the first node
            head = newNode;
            tail = newNode;
        } else {
            pos current = head;
            pos prev = nullptr;

            // Find the correct position to insert the new node
            while (current != nullptr && current->data < x) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                // Insert at the beginning
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                // Insert after prev
                newNode->next = prev->next;
                newNode->prev = prev;
                if (prev->next != nullptr) {
                    prev->next->prev = newNode;
                }
                prev->next = newNode;

                if (newNode->next == nullptr) {
                    // Update tail if the new node is the last node
                    tail = newNode;
                }
            }
        }
        counter++;
    }

    // Print the list
    void printList() {
        pos p = head;
        while (p != nullptr) {
            cout << p->data << "  ";
            p = p->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyList list;

    // Insert elements into the list in sorted order
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);
    list.insert(6);

    // Print the sorted list
    cout << "Sorted List: ";
    list.printList();

    return 0;
}