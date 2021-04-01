#include <bits/stdc++.h>

using namespace std;

int N;
int cache[11];

void initCache() {
    memset(cache, -1, 11 * sizeof(int));
}

void input() {
    cin >> N;
}

int solve(int num) {
    if (num == 1) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    for (int i = 1; i <= num / 2; i++) {
        ret = max(ret, i * (num - i) + solve(i) + solve(num - i));
    }
    return ret;
}

int main() {
    initCache();
    input();
    cout << solve(N);
}