#include <bits/stdc++.h>

using namespace std;

int T, * n;
long long cache[100001][4];
vector<long long> answers;

void initCache() {
    cache[1][0] = 1;
    cache[1][1] = 0;
    cache[1][2] = cache[1][3] = 1;

    cache[2][0] = 1;
    cache[2][2] = 0;
    cache[2][1] = cache[2][3] = 1;

    cache[3][0] = 3;
    cache[3][1] = cache[3][2] = cache[3][3] = 2;
}

void input() {
    cin >> T;
    n = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> n[i];
    }
}

void solve() {
    for (int i = 4; i <= 100000; i++) {
        cache[i][0] = (cache[i - 1][1] + cache[i - 2][2] + cache[i - 3][3]) % 1000000009;
        cache[i][1] = (cache[i - 2][2] + cache[i - 3][3]) % 1000000009;
        cache[i][2] = (cache[i - 1][1] + cache[i - 3][3]) % 1000000009;
        cache[i][3] = (cache[i - 1][1] + cache[i - 2][2]) % 1000000009;
    }
}

void getAnswer() {
    solve();
    for (int i = 0; i < T; i++) {
        answers.push_back(cache[n[i]][0]);
    }
}

void output() {
    for (long long ans: answers) {
        cout << ans << '\n';
    }
}

int main() {
    initCache();
    input();
    getAnswer();
    output();
}