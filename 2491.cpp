#include <bits/stdc++.h>

using namespace std;

int N, * seq, cacheIncrease[100001], cacheDecrease[100001];

void initCache() {
    memset(cacheIncrease, -1, 100001 * sizeof(int));
    memset(cacheDecrease, -1, 100001 * sizeof(int));
}

void input() {
    cin >> N;
    seq = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        seq[i] = num;
    }
}

int countIncreaseSeq() {
    int cnt = -1;
    for (int i = N; i >= 1; i--) {
        int& ret = cacheIncrease[i];
        ret = 1;
        if (i < N && seq[i] <= seq[i + 1]) ret += cacheIncrease[i + 1];
        cnt = max(cnt, ret);
    }
    return cnt;
}

int countDecreaseSeq() {
    int cnt = -1;
    for (int i = N; i >= 1; i--) {
        int& ret = cacheDecrease[i];
        ret = 1;
        if (i < N && seq[i] >= seq[i + 1]) ret += cacheDecrease[i + 1];
        cnt = max(cnt, ret);
    }
    return cnt;
}

int main() {
    initCache();
    input();
    cout << max(countIncreaseSeq(), countDecreaseSeq());
}