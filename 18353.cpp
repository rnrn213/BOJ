#include <bits/stdc++.h>

using namespace std;

int N, soldiers[2001], cache[2001];

void initCache() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> soldiers[i];
    }
}

int solve(int idx) {
    if (idx == N) return cache[N] = 1;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = idx + 1; i <= N; i++) {
        if (soldiers[idx] > soldiers[i]) ret = max(ret, 1 + solve(i));
    }
    return ret;
}

int getAnswer() {
    for (int i = N; i >= 1; i--) {
        solve(i);
    }
    return N - *max_element(cache + 1, cache + N + 1);
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}