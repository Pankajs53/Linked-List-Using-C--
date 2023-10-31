#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* tail;

    Node(){
        this->data=0;
        this->next = NULL;
        this->tail = NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->tail=NULL;
    }

    // desctructor
    ~Node() {
        cout << "Node with value: " << this->data << "deleted" << endl;
        delete next;
    }
};

// Function to print the linked list
void Print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to find the length of the linked list
int findLength(Node* head) {
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

// Function to insert at the head of the linked list
void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    // If the linked list is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    // If the linked list is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node at a given position in the linked list
void insertAtPosition(Node* &head, Node* &tail, int data, int Position) {
    // Get the length of the linked list
    int length = findLength(head);
    // Handle cases where Position is out of bounds
    if (Position < 0 || Position > length) {
        cout << "Invalid position for insertion." << endl;
        return;
    }
    // Check if the linked list is empty
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Insert at the head
    if (Position == 0) {
        insertAtHead(head, tail, data);
        return;
    }
    // Insert at the tail
    if (Position >= length) {
        insertAtTail(head, tail, data);
        return;
    }
    // Insert in between head and tail
    int i = 0;
    Node* Prev = head;
    while (i < Position - 1) {
        Prev = Prev->next;
        i++;
    }
    Node* curr = Prev->next;
    // Create new node
    Node* newNode = new Node(data);
    newNode->next = curr;
    Prev->next = newNode;
}

// Function to insert a node after a specific data value in the linked list
bool insertAfterData(Node* &head, Node* &tail, int beforeData, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == beforeData) {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;

            // If the new node is inserted at the end, update the tail pointer
            if (newNode->next == NULL) {
                tail = newNode;
            }
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 100);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 300);
    insertAtTail(head, tail, 400);
    cout << "Original Linked List: ";
    Print(head);
    cout << endl;

    cout << "Inserting 1000 at position 1:" << endl;
    insertAtPosition(head, tail, 1000, 1);
    Print(head);

    cout << "Inserting 2000 after data 200:" << endl;
    if (insertAfterData(head, tail, 200, 2000)) {
        cout << "Data inserted successfully." << endl;
    } else {
        cout << "Data not found in LL. Insertion failed." << endl;
    }
    Print(head);

    // Memory cleanup will happen automatically when the program ends.
    return 0;
}
