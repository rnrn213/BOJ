#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<int> > v, partialSum;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    v = vector< vector<int> >(N, vector<int>(N));
    partialSum = vector< vector<int> >(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (i > 0) {
                partialSum[i][j] += partialSum[i - 1][j];
            }
            if (j > 0) {
                partialSum[i][j] += partialSum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                partialSum[i][j] -= partialSum[i - 1][j - 1];
            }
            partialSum[i][j] += v[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //cout << partialSum[x2 - 1][y2 - 1] - partialSum[x2 - 1][y1 - 1 - 1] - partialSum[x1 - 1 - 1][y2 - 1] + partialSum[x1 - 1 - 1][y1 - 1 - 1] << "\n";
        int ans = partialSum[x2 - 1][y2 - 1];
        if (x1 > 1) {
            ans -= partialSum[x1 - 1 - 1][y2 - 1];
        }
        if (y1 > 1) {
            ans -= partialSum[x2 - 1][y1 - 1 - 1];
        }
        if (x1 > 1 && y1 > 1) {
            ans += partialSum[x1 - 1 - 1][y1 - 1 - 1];
        }
        cout << ans << "\n";
    }
}