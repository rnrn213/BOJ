#include <bits/stdc++.h>

using namespace std;

int N, cache[2][1001];
string ans;

void initCache() {
    memset(cache, -1, 2 * 1001 * sizeof(int));
}

void input() {
    cin >> N;
}

int solve(int turn, int num) {
    if (num == 1 || num == 3 || num == 4) return turn;
    if (num == 2) return abs(turn - 1);

    int& ret = cache[turn][num];
    if (ret != -1) return ret;
    if (turn == 1) return ret = max({solve(0, num - 1), solve(0, num - 3), solve(0, num - 4)});
    else return ret = min({solve(1, num - 1), solve(1, num - 3), solve(1, num - 4)});
}

void output(int result) {
    if (result == 1) ans = "CY";
    else ans = "SK";

    cout << ans;
}

int main() {
    initCache();
    input();
    output(solve(0, N));
}