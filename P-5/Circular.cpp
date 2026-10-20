#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


void insertBeginning(Node*& head, Node*& tail, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
        return;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head;
}


void insertEnd(Node*& head, Node*& tail, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
        return;
    }

    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}


void deleteValue(Node*& head, Node*& tail, int value) {

    if (head == nullptr)
        return;

  
    if (head == tail) {
        if (head->data == value) {
            delete head;
            head = tail = nullptr;
        }
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {

        if (temp->next->data == value) {

            Node* del = temp->next;

            temp->next = del->next;

            if (del == tail)
                tail = temp;

            delete del;

            tail->next = head;
            return;
        }

        temp = temp->next;
    }
}


void display(Node* head) {

    if (head == nullptr) {
        cout << "Circle is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    insertEnd(head, tail, 1);
    cout << "After joining 1: ";
    display(head);

    insertEnd(head, tail, 2);
    cout << "After joining 2: ";
    display(head);

    insertBeginning(head, tail, 3);
    cout << "After joining 3 at beginning: ";
    display(head);

    deleteValue(head, tail, 2);
    cout << "After student 2 leaves: ";
    display(head);

    return 0;
}