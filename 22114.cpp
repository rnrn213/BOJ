#include <bits/stdc++.h>

using namespace std;

int N, K, cache[100001][2];
vector<int> L;

int solve(int b, int j) {
    if (b == N - 1)
        return 0;
    
    int &ret = cache[b][j];
    if (ret != -1)
        return ret;
    ret = 0;

    if (L[b] <= K)
        ret = solve(b + 1, j) + 1;
    else if (j == 1)
        ret = solve(b + 1, 0) + 1;
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;

    L = vector<int>(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> L[i];
    }

    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        ans = max(ans, 1 + solve(i, 1));
    }
    
    cout << ans;
}