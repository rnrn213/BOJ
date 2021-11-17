#include <bits/stdc++.h>

using namespace std;

int N, K, moveKnight[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

double cache[51][51][51], totalMove = 0.0;

double solve(int y, int x, int moveCnt) {
    if (moveCnt == 0)
        return 1.0;
    
    double& ret = cache[y][x][moveCnt];
    if (ret >= -1.0 * numeric_limits<double>::epsilon())
        return ret;
    ret = 0.0;


    for (int i = 0; i < 8; i++) {
        if (y + moveKnight[i][0] >= 1 && y + moveKnight[i][0] <= N && x + moveKnight[i][1] >= 1 && x + moveKnight[i][1] <= N) {
            ret += solve(y + moveKnight[i][0], x + moveKnight[i][1], moveCnt - 1);
        }
    }

    return ret;
}

int main() {
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int m = 0; m < 51; m++) {
                cache[i][j][m] = -1.0;
            }
        }
    }

    int x, y;
    cin >> N >> x >> y >> K;

    if (K == 0)
        cout << 1;
    else {

        int moveCnt = K;
        solve(y, x, moveCnt);


        cout << fixed;
        cout.precision(10);
        cout << cache[y][x][K] / pow(8, K);
    }

}