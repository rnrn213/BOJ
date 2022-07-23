#include <bits/stdc++.h>

using namespace std;

int N, M, K, r[101][101];
long long cache[101][101];

long long solve(int x, int y) {
    if (x == N && y == M)
        return 1;
    if (r[y][x] == 3)
        return 0;

    long long& ret = cache[y][x];
    if (ret != -1)
        return ret;
    ret = 0;

    if (r[y][x] != 1 && x + 1 <= N)
        ret += solve(x + 1, y);
    if (r[y][x] != 2 && y + 1 <= M)
        ret += solve(x, y + 1);
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    memset(r, 0, sizeof(r));

    cin >> N >> M >> K;


    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (c > a || d > b) {
            if (c > a && (r[b][a] != 1 && r[b][a] != 3)) {
                r[b][a] += 1;
            }
            else if (r[b][a] != 2 && r[b][a] != 3) {
                r[b][a] += 2;
            }
        }
        else {
            if (a > c && (r[d][c] != 1 && r[d][c] != 3)) {
                r[d][c] += 1;
            }
            else if (r[d][c] != 2 && r[d][c] != 3) {
                r[d][c] += 2;
            }
        }
    }

    cout << solve(0, 0);
}