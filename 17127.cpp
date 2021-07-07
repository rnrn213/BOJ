#include <bits/stdc++.h>

using namespace std;

int N, A[11];

int solve(int start, int group) {
    if (group == 5) return 0;

    int P = 1, ret = 0;
    for (int i = start; i <= N - (4 - group); i++) {
        P *= A[i];
        ret = max(ret, P + solve(i + 1, group + 1));
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cout << solve(1, 1);
}