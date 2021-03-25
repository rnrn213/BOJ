#include <bits/stdc++.h>

using namespace std;



int N;
bool SKWin[1001];
string ans;

void input() {
    cin >> N;
}

void initSKWin() {
    memset(SKWin, false, 1001 * sizeof(bool));
    SKWin[2] = SKWin[4] = true;
}

bool rock(int n) {
    for (int i = 5; i <= n; i++) {
        SKWin[i] = !(SKWin[i - 1] && SKWin[i - 3]);
    }
    return SKWin[n];
}

void solve() {
    initSKWin();
    if (rock(N)) ans = "SK";
    else ans = "CY";
}

void output() {
    cout << ans;
}

int main() {
    input();
    solve();
    output();
}