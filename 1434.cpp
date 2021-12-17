#include <bits/stdc++.h>

using namespace std;

int A[51], B[51];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    
    int j = 1, waste = 0;
    for (int i = 1; i <= N; i++) {
        while (j <= M && A[i] >= B[j]) {
            A[i] -= B[j++];
        }
        waste += A[i];
    }

    cout << waste;
}