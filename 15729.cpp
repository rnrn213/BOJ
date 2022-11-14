#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N, 0), B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int btnCnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            A[i] = !A[i];
            if (i < N - 1) A[i + 1] = !A[i + 1];
            if (i < N - 2) A[i + 2] = !A[i + 2];

            btnCnt++;
        }
    }

    cout << btnCnt;
}