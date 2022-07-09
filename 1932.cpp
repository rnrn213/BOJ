#include <bits/stdc++.h>

using namespace std;

int n;
int t[500][500], cache[500][500];

int getMaxSum(int y, int x) {
    if (y == n - 1)
        return t[y][x];
    
    int& ret = cache[y][x];
    if (ret != -1)
        return ret;

    return ret = max(t[y][x] + getMaxSum(y + 1, x), t[y][x] + getMaxSum(y + 1, x + 1));
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cin >> n;
    int rowSize = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rowSize; j++) {
            cin >> t[i][j];
        }
        rowSize++;
    }

    cout << getMaxSum(0, 0);
}