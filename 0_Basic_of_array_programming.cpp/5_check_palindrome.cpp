#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = n - 1;
    bool palindrome = true;

    while(i < j) {
        if(arr[i] != arr[j]) {
            palindrome = false;
            break;
        }
        i++;
        j--;
    }

    if(palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}