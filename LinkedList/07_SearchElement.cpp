#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool searchElement(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 11);
    insertAtEnd(head, 22);
    insertAtEnd(head, 33);
    insertAtEnd(head, 44);

    cout << "Linked List: ";
    display(head);

    int key = 33;
    cout << "Searching " << key << ": ";
    cout << (searchElement(head, key) ? "Found" : "Not Found") << endl;

    key = 99;
    cout << "Searching " << key << ": ";
    cout << (searchElement(head, key) ? "Found" : "Not Found") << endl;

    return 0;
}
