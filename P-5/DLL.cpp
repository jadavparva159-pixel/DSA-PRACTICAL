#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

void insertBeginning(Node*& head, Node*& tail, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


void insertEnd(Node*& head, Node*& tail, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


void insertAfter(Node*& head, Node*& tail, int key, int value) {

    Node* temp = head;

    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

   
    if (temp == nullptr) {
        cout << "Song not found\n";
        return;
    }

    Node* newNode = new Node(value);

   
    newNode->next = temp->next;
    newNode->prev = temp;

   
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    else {
        
        tail = newNode;
    }

    
    temp->next = newNode;
}


void deleteFirst(Node*& head, Node*& tail) {

    if (head == nullptr) {
        cout << "Playlist is empty\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }
    else {
        head->prev = nullptr;
    }

    delete temp;
}


int countSongs(Node* head) {

    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}


void display(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    
    insertBeginning(head, tail, 20);
    cout << "After adding 20 at beginning: ";
    display(head);

    insertBeginning(head, tail, 10);
    cout << "After adding 10 at beginning: ";
    display(head);


    insertEnd(head, tail, 30);
    cout << "After adding 30 at end: ";
    display(head);

    insertAfter(head, tail, 20, 25);
    cout << "After inserting 25 after 20: ";
    display(head);

   
    deleteFirst(head, tail);
    cout << "After deleting first song: ";
    display(head);

   
    cout << "Number of songs: " << countSongs(head) << endl;

    return 0;
}