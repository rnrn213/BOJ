#include <bits/stdc++.h>

using namespace std;

const int ERR = 10000000;
int n;
int cache[100001];

void input() {
    cin >> n;
}

void initCache() {
    for (int i = 0; i <= 100000; i++) {
        cache[i] = -1;
    }
}

int countCoin(int c) {
    if (c == 2 || c == 5) {
        return 1;
    }
    if (c <= 1 || c == 3) {
        return ERR;
    }

    int& ret = cache[c];
    if (ret != -1) return ret;

    return ret = min(1 + countCoin(c - 2), 1 + countCoin(c - 5));
}

void output(int result) {
    if (result >= ERR) cout << -1;
    else cout << result;
}

int main() {
    input();
    initCache();
    int result = countCoin(n);
    output(result);
}