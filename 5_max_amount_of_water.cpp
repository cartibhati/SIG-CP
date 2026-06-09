#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        int maxArea = 0;

        while (i < j) {
            area = (j - i) * min(height[i], height[j]);
            maxArea = max(maxArea, area);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return maxArea;
    }
};

int main() {
    int n;
    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    cout << "Maximum Area = " << obj.maxArea(height) << endl;

    return 0;
}