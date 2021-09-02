#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > rectangle(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &rectangle[i][j]);
        }
    }

    int ans = 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int scope = (N - y > M - x) ? M - x : N - y;
            for (int i = 1; i < scope; i++) {
                if (rectangle[y][x] == rectangle[y + i][x] && rectangle[y][x] == rectangle[y][x + i] &&
                        rectangle[y][x] == rectangle[y + i][x + i])
                    ans = max(ans, (i + 1) * (i + 1));
            }
        }
    }

    cout << ans;
}