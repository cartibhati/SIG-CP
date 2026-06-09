#include <iostream>
#include <string>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;

    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }

    return sum;
}

int cyclicRightShift(int n) {
    string s = to_string(n);

    char last = s.back();
    s.pop_back();

    s = last + s;

    return stoi(s);
}

int main() {
    int rpm;
    cin >> rpm;

    int maxRPM = rpm * 8;
    int finalRPM = rpm;

    for (int year = 1; year <= 10; year++) {

        int a = sumOfSquares(finalRPM) * 323;

        int shifted = cyclicRightShift(finalRPM);

        int lastTwoDigits = shifted % 100;

        int newRPM = a + lastTwoDigits;

        finalRPM = newRPM;

        if (finalRPM > maxRPM)
            break;
    }

    cout << "Final RPM = " << finalRPM << endl;

    return 0;
}