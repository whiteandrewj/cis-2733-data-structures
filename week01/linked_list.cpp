#include <iostream>
#include <assert.h>

using namespace std;

//code adapted from examples at https://www.geeksforgeeks.org/data-structures/linked-list/

template <typename T>
class Node {
public:
    T data;
    Node *next;
    //void printList(Node*);
    //void push(Node**,T);
};

template <typename T>
void printList(Node<T> *n) {
    while (n != NULL) {
        cout << n->data << ", ";
        n = n->next;
    }
}

template <typename T>
void push(Node<T> **headRef, T newData) {
    Node<T> *newNode = new Node<T>();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

template<typename T>
void insertAfter(Node<T> *prevNode, T newData) {
    if (prevNode == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    Node<T> *newNode = new Node<T>();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

template <typename T>
void append(Node<T> **headRef, T newData) {
    Node<T> *newNode = new Node<T>();
    Node<T> *last = *headRef;
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

template <typename T>
void deleteNode(Node<T> **headRef, T key) {
    Node<T> *temp = *headRef;
    Node<T> *prev = NULL;
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

template <typename T>
void deleteNodeIdx(Node<T> **headRef, int index) {
    if (*headRef == NULL) { return; }
    Node<T> *temp = *headRef;
    if (index == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) { return; } //if index is greater than # of elements
    Node<T> *next = temp->next->next; //store pointer to the node next after the one to be deleted
    free(temp->next);
    temp->next = next;
}

template <typename T>
void deleteList(Node<T> **headRef) {
    Node<T> *current = *headRef;
    Node<T> *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

template <typename T>
int getSize(Node<T> *head) {
    int count = 0;
    Node<T> *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
bool search(Node<T> *head, T key) {
    Node<T> *current = head;
    while (current != NULL) {
        if (current->data == key) { return true; }
        current = current->next;
    }
    return false;
}

template <typename T>
T getNth(Node<T> *head, int index) {
    Node<T> *current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) { return current->data; }
        count++;
        current = current->next;
    }
    assert(0);
}

template <typename T>
int count(Node<T> *head, T key) {
    Node<T> *current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == key) { count++; }
        current = current->next;
    }
    return count;
}

int main()
{
    Node<string> *head = NULL;
    push<string>(&head,"a string");
    insertAfter<string>(head,"another string");
    append<string>(&head,"a third string");
    cout << "String type linked list: ";
    printList(head);
    cout << endl << "Deleting node at position 0..." << endl;
    deleteNodeIdx(&head, 0);
    cout << "String linked list: ";
    printList(head);
    cout << endl << "Deleting string 'a third string'..." << endl;
    deleteNode<string>(&head,"a third string");
    cout << "String linked list: ";
    printList(head);
    cout << endl << "Deleting string linked list..." << endl;
    deleteList(&head);
    printList(head);
    cout << endl;

    Node<double> *head2 = NULL;
    append(&head2, 25.3);
    append(&head2, 40.32);
    append(&head2, 2.22);
    push(&head2, 0.01);
    cout << "Double type linked list: ";
    printList(head2);
    cout << endl << "Size of list: " << getSize(head2) << endl;
    cout << boolalpha;
    cout << "Does list containd 10.5? : " << search(head2, 10.5) << endl;
    cout << "Does list contain 2.22? : " << search(head2, 2.22) << endl;
    cout << noboolalpha;
    cout << "The element at index 2 is: " << getNth(head2, 2) << endl;
    cout << "Deleting double linked list..." << endl;
    deleteList(&head2);
    printList(head2);
    cout << endl;

    Node<bool> *head3 = NULL;
    append(&head3, true);
    append(&head3, false);
    append(&head3, false);
    insertAfter(head3->next->next, true);
    push(&head3, false);
    cout << boolalpha;
    cout << "Bool type linked list: ";
    printList(head3);
    cout << endl << "Count of 'false' in list: " << count(head3, false) << endl;
    cout << "Count of 'true' in list: " << count(head3, true) << endl;
    cout << "Deleting node at index 1..." << endl;
    deleteNodeIdx(&head3, 1);
    cout << "Bool linked list: ";
    printList(head3);
    cout << endl << "Deleting 'true' from list...";
    deleteNode(&head3, true);
    cout << endl << "Bool linked list: ";
    printList(head3);
    cout << endl << "Deleting bool linked list..." << endl;
    deleteList(&head3);
    printList(head3);




    return 0;
}