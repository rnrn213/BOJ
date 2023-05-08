#include <bits/stdc++.h>

using namespace std;

int cache[100][100][100], S0size, S1size, S2size;
string S[3];

int solve(int i, int j, int k) {
    if (i == S0size || j == S1size || k == S2size) return 0;

    int& ret = cache[i][j][k];
    if (ret != -1) return ret;
    ret = 0;

    if (S[0][i] == S[1][j] && S[1][j] == S[2][k])
        ret = 1 + solve(i + 1, j + 1, k + 1);

    ret = max({ret, solve(i + 1, j, k), solve(i, j + 1, k), solve(i, j, k + 1)});
    ret = max({ret, solve(i + 1, j + 1, k), solve(i + 1, j, k + 1), solve(i, j + 1, k + 1)});
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> S[0] >> S[1] >> S[2];
    S0size = S[0].size(); S1size = S[1].size(); S2size = S[2].size();

    cout << solve(0, 0, 0);
}