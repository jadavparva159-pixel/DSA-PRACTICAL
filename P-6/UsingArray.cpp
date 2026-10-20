
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    void displayTop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Current top: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display Top\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                s.displayTop();
                break;

            case 2:
                s.pop();
                s.displayTop();
                break;

            case 3:
                s.displayTop();
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

