#include <bits/stdc++.h>

using namespace std;

int T, W, cache[1000][31][2], plum[1000][2];

int solve(int time, int move, int pos) {
    if (time == T)
        return 0;
    
    int& ret = cache[time][move][pos];
    if (ret != -1)
        return ret;
    ret = plum[time][pos] + solve(time + 1, move, pos);

    if (move < W)
        ret = max(ret, plum[time][!pos] + solve(time + 1, move + 1, !pos));
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(cache, -1, sizeof(cache));
    memset(plum, 0, sizeof(plum));

    cin >> T >> W;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        if (n == 1)
            plum[i][0] = 1;
        else
            plum[i][1] = 1;
    }

    cout << solve(0, 0, 0);
}