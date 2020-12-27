#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int R, C, W;
    cin >> R >> C >> W;

    vector< vector<long long> > v = { {0}, {1} };
    for (int i = 2; i < R + W; i++) {
        vector<long long> temp;
        for (int j = 0; j < v[i - 1].size() + 1; j++) {
            if (j == 0 || j == v[i - 1].size()) {
                temp.push_back(1);
            }
            else {
                temp.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
        }
        v.push_back(temp);
    }

    long long ans = v[R][C - 1];
    int t = 1;
    for (int i = 1; i < W; i++) {
        for (int j = C - 1; j <= C - 1 + t; j++) {
            ans += v[R + i][j];
        }
        t++;
    }
    cout << ans;
}