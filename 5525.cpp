#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string P = "I";
    for (int i = 0; i < N; i++) {
        P += "OI";
    }
    string S;
    cin >> S;

    vector<int> SP(M, 0);
    for (int i = M - 3; i >= 0; i--) {
        if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I')
            SP[i] = 1 + SP[i + 2];
    }

    int cnt = 0;
    for (int i = 0; i <= M - (2*N + 1); i++) {
        if (SP[i] >= N)
            cnt++;
    }

    cout << cnt;
}