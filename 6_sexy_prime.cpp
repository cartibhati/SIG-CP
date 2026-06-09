#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Sexy Prime Pairs:\n";

    for (int i = 2; i + 6 <= N; i++) {
        if (isPrime(i) && isPrime(i + 6)) {
            cout << "(" << i << ", " << i + 6 << ")\n";
        }
    }

    return 0;
}