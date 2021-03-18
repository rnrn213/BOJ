#include <bits/stdc++.h>

using namespace std;

int cache[50001];

void initCache() {
    cache[0] = -1;
    for (int i = 1; i <= 50000; i++) {
        cache[i] = 5;
    }
}

int fourSquares(int n) {
    if (n == 0) return 0;

    int m = sqrt(n);
    int& ret = cache[n];
    if (ret != 5) return ret;
    for (int i = m; i >=1; i--) {
        ret = min(ret, 1 + fourSquares(n - pow(i, 2)));
    }
    return ret;
}

int main() {
    initCache();
    int n;
    cin >> n;
    cout << fourSquares(n);
}