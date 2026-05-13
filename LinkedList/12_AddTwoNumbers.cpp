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

Node* addTwoNumbers(Node* first, Node* second) {
    Node* answer = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0) {
        int sum = carry;

        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }

        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        insertAtEnd(answer, sum % 10);
        carry = sum / 10;
    }

    return answer;
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

    insertAtEnd(first, 2);
    insertAtEnd(first, 4);
    insertAtEnd(first, 3);

    insertAtEnd(second, 5);
    insertAtEnd(second, 6);
    insertAtEnd(second, 4);

    cout << "First Number: ";
    display(first);

    cout << "Second Number: ";
    display(second);

    Node* answer = addTwoNumbers(first, second);

    cout << "Sum: ";
    display(answer);

    return 0;
}
