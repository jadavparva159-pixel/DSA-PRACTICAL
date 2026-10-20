
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patient;
    Node* next;

    Node(string name) {
        patient = name;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a patient to the back of the queue
    void arrive(string name) {
        Node* newNode = new Node(name);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << name << " arrived." << endl;
        displayFront();
    }

    // Attend the patient at the front
    void attend() {
        if (front == nullptr) {
            cout << "Ward is empty! No patient to attend." << endl;
            return;
        }

        Node* temp = front;

        cout << temp->patient << " is attended." << endl;

        front = front->next;

        // If the last patient was removed
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        displayFront();
    }

    // Display the current front patient
    void displayFront() {
        if (front == nullptr) {
            cout << "No patients waiting." << endl;
        } else {
            cout << "Front patient: " << front->patient << endl;
        }
    }

    // Release remaining nodes
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout << "\n1. Patient Arrives\n";
        cout << "2. Attend Patient\n";
        cout << "3. Display Front\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> ws;
                getline(cin, name);
                q.arrive(name);
                break;

            case 2:
                q.attend();
                break;

            case 3:
                q.displayFront();
                break;

            case 0:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}

