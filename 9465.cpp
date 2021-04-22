#include <bits/stdc++.h>

using namespace std;

int T, n, cache[2][100000];
vector<int> stickers[2];

void initCache() {
    //memset(cache, -1, sizeof(cache));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 100000; j++) {
            cache[i][j] = -1;
        }
    }
}

void inputStickers() {
    int num;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            stickers[i].push_back(num);
        }
    }
}

int solve(int line, int idx) {
    if (idx == n) return 0;

    int& ret = cache[line][idx];
    if (ret != -1) return ret;

    if (line) {
        ret = max(solve(line, idx + 1), stickers[line][idx] + solve(line - 1, idx + 1));
    }
    else {
        ret = max(solve(line, idx + 1), stickers[line][idx] + solve(line + 1, idx + 1));
    }
    return ret;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        initCache();
        cin >> n;
        inputStickers();
        for (int i = n - 1; i >= 1; i--) {
            solve(0, i);
            solve(1, i);
        }
        cout << max(solve(0, 0), solve(1, 0)) << '\n';
        stickers[0].clear();
        stickers[1].clear();
    }
}