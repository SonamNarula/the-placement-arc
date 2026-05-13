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

Node* mergeSortedLists(Node* first, Node* second) {
    Node dummy(0);
    Node* tail = &dummy;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    if (first != NULL) {
        tail->next = first;
    } else {
        tail->next = second;
    }

    return dummy.next;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* first = NULL;
    Node* second = NULL;

    insertAtEnd(first, 1);
    insertAtEnd(first, 3);
    insertAtEnd(first, 5);

    insertAtEnd(second, 2);
    insertAtEnd(second, 4);
    insertAtEnd(second, 6);

    cout << "First List: ";
    display(first);

    cout << "Second List: ";
    display(second);

    Node* merged = mergeSortedLists(first, second);

    cout << "Merged List: ";
    display(merged);

    return 0;
}
