#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    // default const
    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

};


// Function to print the circular doubly linked list
void Print(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to find the length of the circular doubly linked list
int findLength(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int length = 0;
    Node* temp = head;
    do {
        length++;
        temp = temp->next;
    } while (temp != head);

    return length;
}

// Function to insert a node at the head of the circular doubly linked list
void InsertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// Function to insert a node at the tail of the circular doubly linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node at a specific position in the circular doubly linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int Position) {
    int len = findLength(head);

    // Check if the position is out of bounds
    if (Position <= 0 || Position > len + 1) {
        cout << "Invalid position. Cannot insert." << endl;
        return;
    }

    // Insert at the head
    if (Position == 1) {
        InsertAtHead(head, tail, data);
        return;
    }

    // Insert at the tail
    if (Position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < Position - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete a node from a specific position in the circular doubly linked list
void deleteFromPosition(Node* &head, Node* &tail, int Position) {
    int len = findLength(head);

    // Check if the position is out of bounds
    if (Position <= 0 || Position > len) {
        cout << "Invalid position or empty LL. Cannot delete." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < Position; i++) {
        temp = temp->next;
    }

    Node* prevNode = temp->prev;
    Node* forwNode = temp->next;

    // If deleting the head node, update head pointer
    if (temp == head) {
        head = forwNode;
    }
    // If deleting the tail node, update tail pointer
    if (temp == tail) {
        tail = prevNode;
    }

    prevNode->next = forwNode;
    forwNode->prev = prevNode;

    // Deallocate temp node
    delete temp;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert elements into the circular linked list
    InsertAtHead(head, tail, 1);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 3);

    // Print the circular linked list
    cout << "Original List: ";
    Print(head);

    // Insert at tail
    insertAtTail(head, tail, 1000);
    cout << "List after inserting 1000 at tail: ";
    Print(head);

    // Insert at position
    insertAtPosition(head, tail, 10, 1);
    cout << "List after inserting 10 at position 1: ";
    Print(head);

    // Delete from position
    deleteFromPosition(head, tail, 1);
    cout << "List after deleting node at position 1: ";
    Print(head);

    return 0;
}
