#include <bits/stdc++.h>

using namespace std;

int N;
bool isWin[1000];

void input() {
    cin >> N;
}

void initIsWin() {
    isWin[0] = isWin[2] = true;
    isWin[1] = false;

    for (int i = 3; i < 1000; i++) {
        isWin[i] = !(isWin[i - 1] || isWin[i - 3]);
    }
}

void solve() {
    initIsWin();
    if (isWin[N - 1]) cout << "SK";
    else cout << "CY";
}

int main() {
    input();
    solve();
}