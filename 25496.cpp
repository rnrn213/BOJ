#include <bits/stdc++.h>

using namespace std;

int P, N, A[1000];

int main() {
    cin >> P >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    int i = 0, cnt = 0;
    while (P < 200 && i < N) {
        P += A[i];
        cnt++;
        i++;
    }

    cout << cnt;
}