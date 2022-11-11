#include <bits/stdc++.h>

using namespace std;

int N, cache[1001][10];

int solve(int length, int lastNum) {
    if (length == N - 1) return 1;

    int& ret = cache[length + 1][lastNum];
    if (ret != -1) return ret;
    ret = 0;

    for (int nextNum = lastNum; nextNum < 10; nextNum++) {
        ret = (ret + solve(length + 1, nextNum)) % 10007;
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(-1, 0);
}