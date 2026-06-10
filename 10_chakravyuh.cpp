#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> mat(N, vector<int>(N));

    vector<pair<int, int>> powerPoints;

    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;

    int num = 1;

    while (top <= bottom && left <= right) {

        // Left -> Right
        for (int j = left; j <= right; j++) {
            mat[top][j] = num;

            if (num == 1 || num % 11 == 0)
                powerPoints.push_back({top, j});

            num++;
        }
        top++;

        // Top -> Bottom
        for (int i = top; i <= bottom; i++) {
            mat[i][right] = num;

            if (num == 1 || num % 11 == 0)
                powerPoints.push_back({i, right});

            num++;
        }
        right--;

        // Right -> Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                mat[bottom][j] = num;

                if (num == 1 || num % 11 == 0)
                    powerPoints.push_back({bottom, j});

                num++;
            }
            bottom--;
        }

        // Bottom -> Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                mat[i][left] = num;

                if (num == 1 || num % 11 == 0)
                    powerPoints.push_back({i, left});

                num++;
            }
            left++;
        }
    }

    // Print matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Total Power points: " << powerPoints.size() << endl;

    for (auto p : powerPoints) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    return 0;
}
