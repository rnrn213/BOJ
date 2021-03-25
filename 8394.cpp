#include <bits/stdc++.h>

using namespace std;

int n, cache[10000001];

void input() {
    cin >> n;
}

void initCache() {
    memset(cache, -1, 10000001 * sizeof(int));
}

int handShake(int now) {
    int* arr = new int[n + 1];
    memset(arr, -1, (n + 1) * sizeof(int));
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    return arr[n];
}

int main() {
    initCache();
    input();
    cout << handShake(n);
}