#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of buckets: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0,1,2):\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int count0 = 0, count1 = 0, count2 = 0;

    // First pass: Count
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            count0++;
        else if(arr[i] == 1)
            count1++;
        else
            count2++;
    }

    // Second pass: Overwrite
    int index = 0;

    while(count0--)
        arr[index++] = 0;

    while(count1--)
        arr[index++] = 1;

    while(count2--)
        arr[index++] = 2;

    cout << "Sorted colours: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}