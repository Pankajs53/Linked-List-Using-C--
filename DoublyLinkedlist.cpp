#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    // Parameterized constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to find the length of the linked list
int findLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

// Function to print the linked list
void Print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to insert at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    // If the linked list is empty, create a new node and set it as head and tail
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        // Create a new node
        Node* newNode = new Node(data);
        // Update pointers to insert at the head
        newNode->next = head;
        head->prev = newNode;
        // Mark newNode as head
        head = newNode;
    }
}

// Function to insert at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    // If the linked list is empty, create a new node and set it as head and tail
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        // Create a new node
        Node* newNode = new Node(data);
        // Update pointers to insert at the tail
        newNode->prev = tail;
        tail->next = newNode;
        // Mark newNode as tail
        tail = newNode;
    }
}

// Function to insert at a specific position in the linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int Position) {
    int length = findLength(head);
    // Handle cases where Position is out of bounds
    if (Position < 0 || Position > length) {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    // If the linked list is empty or Position is 0, insert at the head
    if (head == NULL || Position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    // If Position is equal to the length, insert at the tail
    if (Position == length) {
        insertAtTail(head, tail, data);
        return;
    }

    // Find the previous and current pointers for insertion
    Node* prev1 = head;
    int i = 0;
    while (i < Position - 1) {
        prev1 = prev1->next;
        i++;
    }
    Node* curr = prev1->next;

    // Create a new node
    Node* newNode = new Node(data);

    // Set the pointers to insert at the specified Position
    newNode->next = curr;
    curr->prev = newNode;

    newNode->prev = prev1;
    prev1->next = newNode;
}

// Function to insert a node after a specific data value in the linked list
bool insertAfterData(Node* &head, Node* &tail, int data, int afterData) {
    int length = findLength(head);
    int i = 0;
    Node* temp = head;
    while (i < length) {
        if (temp->data == afterData) {
            insertAtPosition(head, tail, data, i + 1);
            return true;
        }
        temp = temp->next;
        i++;
    }
    return false;
}

// Main function
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Example usage of linked list functions
    cout << "Original Linked List: ";
    Print(head);

    cout << "\nInserting nodes..." << endl;
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);

    cout << "Linked List after inserting nodes at the head: ";
    Print(head);

    cout << "\nInserting node at Position 5..." << endl;
    insertAtPosition(head, tail, 2, 5);
    cout << "Linked List after inserting node at Position 5: ";
    Print(head);

    cout << "\nInserting node after data 10000..." << endl;
    if (insertAfterData(head, tail, 10, 10000)) {
        cout << "Data inserted successfully." << endl;
    } else {
        cout << "Data not found in LL. Insertion failed." << endl;
    }
    cout << "Linked List after inserting node after data 10000: ";
    Print(head);

    return 0;
}
