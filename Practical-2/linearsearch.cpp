#include <bits/stdc++.h>
using namespace std;

int linearsearch(string arr[], int n, string target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string plates[] = {"GJ01AB1234", "GJ05XY5678", "MH12CD9876", "RJ14PQ1111"};
    int n = 4;

    string target = "MH12CD9876";

    int ans = linearsearch(plates, n, target);

    if(ans != -1)
    {
        cout << "Found at position: " << ans;
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}