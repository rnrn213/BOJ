#include <bits/stdc++.h>

using namespace std;

int N, jump[200001], cache[200001];

int solve(int idx) {
    if (idx > N) return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;

    return ret = 1 + solve(idx + 1 + jump[idx]);

}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> jump[i];
    }

    for (int i = 1; i <= N; i++) {
        solve(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << cache[i] << " ";
    }
}