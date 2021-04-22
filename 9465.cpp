#include <bits/stdc++.h>

using namespace std;

int T, n, cache[2][100000];
vector<int> stickers[2];

void initCache() {
    memset(cache, -1, sizeof(cache));
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

void printCache() {
    cout << "\ncache\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << cache[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        initCache();
        cin >> n;
        inputStickers();
        cout << max(solve(0, 0), solve(1, 0));
        stickers[0].clear();
        stickers[1].clear();

        printCache();
    }
}