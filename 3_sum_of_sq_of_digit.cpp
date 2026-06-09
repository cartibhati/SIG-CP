#include <iostream>
using namespace std;

int sumOf_sq(int n){
    int sum = 0;

    while(n > 0){
        int d = n % 10;
        sum += d * d;
        n = n / 10;
    }

    return sum;
}

int main() {
    int n = 234;
    cout << "The sum is: " << sumOf_sq(n);

    return 0;
}