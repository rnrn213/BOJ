#include <bits/stdc++.h>

using namespace std;

int cache[30][30];
int n, k;

void input() {
    cin >> n >> k;
}

void initCache() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            cache[i][j] = -1;
        }
    }
}

int pascal(int n, int k) {
    if (k == 1 || n == k) return 1;
    if (n == 0) return 0;

    int& ret = cache[n - 1][k -  1];
    if (ret != -1) return ret;

    return ret = pascal(n - 1, k - 1) + pascal(n - 1, k);
}


int main() {
    input();
    initCache();
    cout << pascal(n, k);
}