#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};

    int bestQualities = -1;
    int bestDistance = 1e9;
    int bestRow = -1;
    int bestCol = -1;
    bool tie = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Skip Sam's house
            if (i == 0 && j == 0)
                continue;

            // Girl's house
            if (a[i][j] == 1) {

                int qualities = 0;

                for (int k = 0; k < 8; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        a[nr][nc] != 0) {
                        qualities++;
                    }
                }

                int distance = max(abs(i), abs(j));

                if (qualities > bestQualities) {
                    bestQualities = qualities;
                    bestDistance = distance;
                    bestRow = i;
                    bestCol = j;
                    tie = false;
                }
                else if (qualities == bestQualities) {

                    if (distance < bestDistance) {
                        bestDistance = distance;
                        bestRow = i;
                        bestCol = j;
                        tie = false;
                    }
                    else if (distance == bestDistance) {
                        tie = true;
                    }
                }
            }
        }
    }

    if (bestRow == -1) {
        cout << "No suitable girl found";
    }
    else if (tie) {
        cout << "Polygamy not allowed";
    }
    else {
        cout << bestRow + 1 << ":" 
             << bestCol + 1 << ":" 
             << bestQualities;
    }

    return 0;
}