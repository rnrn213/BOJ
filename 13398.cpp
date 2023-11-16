#include <bits/stdc++.h>

using namespace std;

const int INF = -2100000000;

int n, arr[100000], cache[100001][2];

int solve(int idx, int rm) {
    if (idx == n) return INF;

    int &ret = cache[idx][rm];
    if (ret != INF) return ret;
    ret = arr[idx];

    ret = max(ret, arr[idx] + solve(idx + 1, rm));
    if (rm == 0)
        ret = max(ret, solve(idx + 1, 1));

    return ret;
}

int main() {
    for (int i = 0; i <= 100000; i++) {
        for (int j = 0; j < 2; j++) {
            cache[i][j] = INF;
        }
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(0, 0);

    int ans = INF;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (cache[i][j] > ans)
                ans = cache[i][j];
        }
    }

    cout << ans;
}