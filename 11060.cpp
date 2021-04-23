#include <bits/stdc++.h>

using namespace std;

int N, A[1000], cache[1000];

void initCache() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

int solve(int idx) {
    if (idx == N - 1) return 0;
    if (idx >= N || A[idx] == 0) return 100000;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 100000;
    for (int i = 1; i <= A[idx]; i++) {
        ret = min(ret, 1 + solve(idx + i));
    }
    return ret;
}

int getAnswer() {
    int ans = solve(0);
    if (ans > 10000) ans = -1;
    return ans;
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}