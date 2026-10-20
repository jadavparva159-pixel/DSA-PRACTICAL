
#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void join(int value) {
        if (count == MAX) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;

        cout << value << " joined the queue." << endl;
        displayFront();
    }

    void serve() {
        if (count == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " served." << endl;

        front = (front + 1) % MAX;
        count--;

        displayFront();
    }

    void displayFront() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front token: " << arr[front] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n1. Join\n2. Serve\n3. Display Front\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> token;
                q.join(token);
                break;

            case 2:
                q.serve();
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

