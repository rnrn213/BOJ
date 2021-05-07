#include <bits/stdc++.h>

using namespace std;

int N, score[1001], cache[1001];

void initCache() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }
}

int solve(int idx) {
    if (idx == N) return cache[N] = score[N];

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = score[idx];
    for (int i = idx + 1; i <= N; i++) {
        if (score[idx] < score[i]) 
            ret = max(ret, score[idx] + solve(i));
    }

    return ret;
}

int getAnswer() {
    for (int i = N; i >= 1; i--) {
        solve(i);
    }
    return *max_element(cache + 1, cache + N + 1);
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}