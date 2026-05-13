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

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Cycle present before linking: ";
    cout << (hasCycle(head) ? "Yes" : "No") << endl;

    head->next->next->next->next = head->next;

    cout << "Cycle present after linking: ";
    cout << (hasCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
