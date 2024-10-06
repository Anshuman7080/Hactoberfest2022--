#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data_val) : data(data_val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* middle;
    int count;

    LinkedList() : head(nullptr), middle(nullptr), count(0) {}

    // Function to add a new node
    void pushNode(int data_val) {
        Node* new_node = new Node(data_val);
        
        // Update head
        new_node->next = head;
        head = new_node;

        // Update the middle pointer and count
        count++;
        if (count == 1) {
            middle = new_node;  // First node is the middle
        } else if (count % 2 == 0) {
            middle = middle->next;  // Move the middle pointer forward
        }
    }

    // Utility function to print the linked list
    void printNode() {
        Node* current = head;
        while (current) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Function to print the middle element of the linked list
    void printMiddle() {
        if (middle) {
            cout << "The middle element is [" << middle->data << "]" << endl;
        }
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList linkedList;

    for (int i = 5; i > 0; --i) {
        linkedList.pushNode(i);
        linkedList.printNode();
        linkedList.printMiddle();
    }

    return 0;
}
