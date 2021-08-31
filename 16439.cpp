#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > preference(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> preference[i][j];
        }
    }

    int maxPreference = 0;
    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            for (int k = j + 1; k < M; k++) {
                int sumPreference = 0;
                for (int n = 0; n < N; n++) {
                    sumPreference += max({preference[n][i], preference[n][j], preference[n][k]});
                }
                if (sumPreference > maxPreference)
                    maxPreference = sumPreference;
            }
        }
    }

    cout << maxPreference;
}