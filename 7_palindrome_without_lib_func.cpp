#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0;
    int j = s.length() - 1;

    bool palindrome = true;

    while (i < j) {
        if (s[i] != s[j]) {
            palindrome = false;
            break;
        }
        i++;
        j--;
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}