#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int minCoins = INT_MAX;
    int best5 = 0, best2 = 0, best1 = 0;

    for (int c5 = 0; c5 <= N / 5; c5++) {
        for (int c2 = 0; c2 <= N / 2; c2++) {
            for (int c1 = 0; c1 <= N; c1++) {

                int totalValue = 5 * c5 + 2 * c2 + c1;

                if (totalValue != N)
                    continue;

                int totalCoins = c5 + c2 + c1;

                if (totalCoins < minCoins) {
                    minCoins = totalCoins;
                    best5 = c5;
                    best2 = c2;
                    best1 = c1;
                }
            }
        }
    }

    cout << minCoins << " "
         << best5 << " "
         << best2 << " "
         << best1 << endl;

    return 0;
}