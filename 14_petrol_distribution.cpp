#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);

    vector<int> a;
    int x;

    while (ss >> x)
        a.push_back(x);

    int total = accumulate(a.begin(), a.end(), 0);

    vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int num : a) {
        for (int s = total; s >= num; s--) {
            dp[s] = dp[s] || dp[s - num];
        }
    }

    int best = 0;

    for (int s = total / 2; s >= 0; s--) {
        if (dp[s]) {
            best = s;
            break;
        }
    }

    cout << max(best, total - best);

    return 0;
}