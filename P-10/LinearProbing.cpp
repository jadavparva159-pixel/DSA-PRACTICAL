
#include <iostream>
using namespace std;

int main()
{
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n, id;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter vehicle registration number: ";
        cin >> id;

        int index = id % 10;
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % 10;

            if (index == start)
            {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (table[index] == -1)
            table[index] = id;
    }

    cout << "\nFinal Parking Slots:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}

