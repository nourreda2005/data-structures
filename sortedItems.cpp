#include <iostream>
using namespace std;

// SINGLY LINKED LIST
class node {
public:
    int data; // where an integer is stored in the list
    node* next; // allows me to move from one node to the next
};
typedef node* pos; // pos is now an alias for node*

class list {
private:
    node* head = nullptr;  // points to the first node
    node* tail = nullptr;   // points to the last node
    int counter = 0;
public:

    // Insert function to add elements in ascending order
    void insert(int x) {
        pos newNode = new node; // allocating memory for newNode
        newNode->data = x;  // storing the value x in the newNode
        newNode->next = NULL;

        if (counter == 0) {
            // If the list is empty, insert the new node as the first node
            head = newNode;
            tail = newNode;
        } else {
            pos current = head;
            pos prev = NULL;

            // Find the correct position to insert the new node
            while (current != NULL && current->data < x) {
                prev = current;
                current = current->next;
            }

            if (prev == NULL) {
                // Insert at the beginning
                newNode->next = head;
                head = newNode;
            } else {
                // Insert after prev
                newNode->next = prev->next;
                prev->next = newNode;
            }

            if (newNode->next == NULL) {
                // Update tail if the new node is the last node
                tail = newNode;
            }
        }
        counter++;
    }

    // Print the list
    void printList() {
        pos p = head; // start from the head
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    list l;

    // Insert elements into the list in sorted order
    l.insert(5);
    l.insert(3);
    l.insert(8);
    l.insert(1);
    l.insert(6);

    // Print the sorted list
    cout << "Sorted List: ";
    l.printList();

    return 0;
}