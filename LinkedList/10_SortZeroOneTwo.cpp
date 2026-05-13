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

void sortZeroOneTwo(Node* head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) {
            zeroCount++;
        } else if (temp->data == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        } else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        } else {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
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

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 0);
    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    insertAtEnd(head, 2);

    cout << "Original List: ";
    display(head);

    sortZeroOneTwo(head);

    cout << "Sorted List: ";
    display(head);

    return 0;
}
