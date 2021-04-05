#include <bits/stdc++.h>

using namespace std;

int N;

void input() {
    cin >> N;
}

int solve() {
    int tile[3] = {-1, 1, 2};

    int ret = 0;
    for (int i = 3; i <= N; i++) {
        ret = (tile[1] + tile[2]) % 15746;
        tile[1] = tile[2];
        tile[2] = ret;
    }
    if (N <= 2) return tile[N];
    else return ret;
}

int main() {
    input();
    cout << solve();
}