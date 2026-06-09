#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            int ans = prices[i] - buy;
            profit = max(profit, ans);
        }

        return profit;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Maximum Profit = " << obj.maxProfit(prices) << endl;

    return 0;
}