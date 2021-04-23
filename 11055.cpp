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
    if (idx == N) return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = A[idx];
    for (int i = idx + 1; i < N; i++) {
        if (A[idx] < A[i]) ret = max(ret, A[idx] + solve(i));
    }
    return ret;
}

int getAnswer() {
    for (int i = N - 1; i >= 0; i--) {
        solve(i);
    }
    return *max_element(cache, cache + N);
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}