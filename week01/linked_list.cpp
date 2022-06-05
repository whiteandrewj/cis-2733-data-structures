#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void push(Node **headRef, int newData) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void insertAfter(Node *prevNode, int newData) {
    if (prevNode == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void append(Node **headRef, int newData) {
    Node *newNode = new Node();
    Node *last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

int main()
{
    /*
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 50;
    head->next = second;

    second->data = 70;
    second->next = third;

    third->data = 130;
    third->next = NULL;
    */

    Node *head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    cout << "Created Linked List is: ";
    printList(head);

    return 0;
}