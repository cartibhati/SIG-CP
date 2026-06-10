#include <iostream>
#include <vector>
using namespace std;

long long nCr(int n, int r) {
    if (r > n) return 0;

    if (r > n - r)
        r = n - r;

    long long ans = 1;

    for (int i = 0; i < r; i++) {
        ans *= (n - i);
        ans /= (i + 1);
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R, N;
        cin >> R >> N;

        vector<int> sizes(R);

        int q = N / R;
        int rem = N % R;

        for (int i = 0; i < R; i++) {
            sizes[i] = q + (i < rem);
        }

        long long ans = 1;
        int remaining = N;

        for (int i = 0; i < R; i++) {
            ans *= nCr(remaining, sizes[i]);
            remaining -= sizes[i];
        }

        cout << ans << endl;
    }

    return 0;
}