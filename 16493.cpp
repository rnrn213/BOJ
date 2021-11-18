#include <bits/stdc++.h>

using namespace std;

int N, M, chapter[21][2], cache[1 << 21];

int solve(int days, int readChapter) {
    if (readChapter == (1 << 21))
        return 0;
    
    int& ret = cache[readChapter];
    if (ret != -1)
        return ret;
    ret = 0;

    for (int i = 1; i <= M; i++) {
        if (days + chapter[i][0] <= N && (readChapter & (1 << i)) == 0) {
            ret = max(ret, chapter[i][1] + solve(days + chapter[i][0], readChapter | (1 << i)));
        }
    }

    return ret;
}


int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> chapter[i][0] >> chapter[i][1];
    }

    solve(0, 0);
    cout << cache[0];
}