#include <bits/stdc++.h>

using namespace std;

int n, cup[10001], cache[10001][3];

int solve(int idx, int cnt) {
    if (idx == n) {
        if (cnt == 2)
            return 0;
        else
            return cup[idx];
    }

    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;
    ret = solve(idx + 1, 0);
    if (cnt < 2)
        ret = max(ret, cup[idx] + solve(idx + 1, cnt + 1));
    
    return ret;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= n; i++) {
        cin >> cup[i];
    }

    cout << solve(1, 0);
}