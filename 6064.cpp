#include <bits/stdc++.h>

using namespace std;

int getLcm(int M, int N) {
    int a = M, b = N, r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return (M * N) / a;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int j, lcm = getLcm(M, N);
        for (j = x; j <= lcm; j += M) {
            if (j % N == y || (y == N && j % N == 0)) {
                cout << j;
                break;
            }

        }
        if (j > lcm)
            cout << -1;
        
        cout << "\n";
    }
}