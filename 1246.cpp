#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<int> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i];
    }
    sort(P.begin(), P.end(), greater<>());

    int price = 0, maxEarning = 0;
    for (int i = 0; i < M && i < N; i++) {
        if (P[i] * (i + 1) > maxEarning) {
            maxEarning = P[i] * (i + 1);
            price = P[i];
        }
    }

    cout << price << " " << maxEarning;
}