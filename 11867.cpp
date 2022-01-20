#include <bits/stdc++.h>

using namespace std;

int N, M, cache[2][101][101];

int boxGame(int N, int M, int turn) {
    if (N == 1 && M == 1)
        return 0;
    
    int& ret = cache[turn][N][M];
    if (ret != -1)
        return ret;
    ret = 0;
    
    for (int i = 1; i <= N / 2; i++) {
        ret = ret || !boxGame(i, N - i, !turn);
    }
    for (int i = 1; i <= M / 2; i++) {
        ret = ret || !boxGame(i, M - i, !turn);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;

    if (boxGame(N, M, 0))
        cout << "A";
    else
        cout << "B";
}