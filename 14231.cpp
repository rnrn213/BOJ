#include <bits/stdc++.h>

using namespace std;

int n, A[5000], cache[5001];

int solve(int idx) {
    int& ret = cache[idx + 1];
    if (ret != -1)
        return ret;
    ret = 1;

    for (int i = idx + 1; i < n; i++) {
        if (idx == -1 || A[idx] < A[i]) {
            ret = max(ret, 1 + solve(i));
        }
    }

    return ret;
}

int main() {
    memset(cache, -1, 5001 * sizeof(int));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    solve(-1);

    cout << cache[0] - 1;
}