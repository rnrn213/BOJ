#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> a;

int solve(int snow, int i, int t) {
    if (i >= N || t == M)
        return snow;

    if (i + 2 <= N) {
        return max(solve(snow + a[i + 1], i + 1, t + 1), solve(snow / 2 + a[i + 2], i + 2, t + 1));
    }
    else if (i + 1 <= N)
        return solve(snow + a[i + 1], i + 1, t + 1);
    
    return -1;
}

int main() {
    cin >> N >> M;
    a = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    cout << solve(1, 0, 0);
}