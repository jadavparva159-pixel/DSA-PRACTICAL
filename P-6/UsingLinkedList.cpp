
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        displayCurrentPage();
    }

    void back() {
        if (top == nullptr) {
            cout << "No history available!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        delete temp;

        displayCurrentPage();
    }

    void displayCurrentPage() {
        if (top == nullptr) {
            cout << "No page open." << endl;
        } else {
            cout << "Current page: " << top->page << endl;
        }
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack history;
    int choice;
    string page;

    do {
        cout << "\n1. Visit Page\n2. Back\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                cin >> page;
                history.visit(page);
                break;

            case 2:
                history.back();
                break;

            case 0:
                cout << "Browser closed." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

