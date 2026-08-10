#include<bits/stdc++.h>
using namespace std;

void longestword(string str) {
    stringstream ss(str);
    string word;
    string longest = "";

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << "Longest word: " << longest << endl;
}

int main() {
    string str = "This is a sample string with some long words";
    longestword(str);
    return 0;
}