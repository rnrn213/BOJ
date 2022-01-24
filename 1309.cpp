#include <bits/stdc++.h>

using namespace std;

int N, cache[100001][3];

int solve(int h, int type) {
    if (h == 1)
        return (type == 0) ? 3 : 2;
    
    int &ret = cache[h][type];
    if (ret != -1)
        return ret;
    ret = 0;

    for (int i = 0; i < 3; i++) {
        if (type != 0 && i == type)
            continue;
        
        ret = (ret + solve(h - 1, i)) % 9901;
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cache[1][0] = cache[1][1] = cache[1][2] = 1;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        solve(i, 0);
    }

    if (N == 1)
        cout << 3;
    else
        cout << cache[N][0];
}