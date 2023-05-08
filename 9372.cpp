#include <bits/stdc++.h>

using namespace std;

int T, N, M, A[1001];

int find(int n) {
    if (A[n] == n) return n;

    return find(A[n]);
}



int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            A[i] = i;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            if (find(a) == find(b)) continue;

            A[find(a)] = b;
            cnt++;
        }

        cout << cnt << "\n";
    }
}