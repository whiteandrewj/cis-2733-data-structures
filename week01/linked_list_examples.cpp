#include <iostream>
#include <assert.h>

using namespace std;

//code copied from https://www.geeksforgeeks.org/data-structures/linked-list/

class Node {
public:
    int data;
    Node *next;
};

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << ", ";
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

void deleteNode(Node **headRef, int key) {
    Node *temp = *headRef;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        delete temp;
        return;
    } else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void deleteNodeIdx(Node **headRef, int index) {
    if (*headRef == NULL) { return; }
    Node *temp = *headRef;
    if (index == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) { return; } //if index is greater than # of elements
    Node *next = temp->next->next; //store pointer to the node next after the one to be deleted
    free(temp->next);
    temp->next = next;
}

void deleteList(Node **headRef) {
    Node *current = *headRef;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

int getSize(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool search(Node *head, int x) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == x) { return true; }
        current = current->next;
    }
    return false;
}

int getNth(Node *head, int index) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) { return current->data; }
        count++;
        current = current->next;
    }
    assert(0);
}

int count(Node *head, int key) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == key) { count++; }
        current = current->next;
    }
    return count;
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
    /*
    Node *head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    cout << "Created Linked List is: ";
    printList(head);
    */
    /*
    // Start with the empty list
    Node* head = NULL;
 
    // Add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
 
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
     
    printList(head);
    */

    Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 8);
    push(&head, 8);
 
    cout << "Created Linked List: ";
    printList(head);
    deleteNodeIdx(&head, 3);
    cout << "\nLinked List after Deletion at position 3: ";
    printList(head);
    cout << endl;
    
    cout << "Element at index 3 is " << getNth(head, 3);

    search(head, 8)? cout<<"Yes" : cout<<"No" << endl;

    cout << "Size of list: " << getSize(head) << endl;

    cout << "count of 8 is " << count(head, 8) << endl;
    
    cout << "Deleting linked list";
    deleteList(&head);
 
    cout << "\nLinked list deleted";
    
    return 0;
}