#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector< vector<int> > coins(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> coins[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(coins[0][i]);
    }
    cout << 2 * ans;
}