#include <bits/stdc++.h>

using namespace std;

int n, box[1000], cache[1000];

void initCache() {
    memset(cache, -1, 1000 * sizeof(int));
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }
}

int solve(int idx) {
    if (idx == n) return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = idx + 1; i < n; i++) {
        if (box[idx] < box[i]) ret = max(ret, 1 + solve(i));
    }
    return ret;
}

int getAnswer() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, solve(i));
    }
    return ret;
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}