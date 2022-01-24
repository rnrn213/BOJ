#include <bits/stdc++.h>

using namespace std;

int N, cache[5001];
vector<int> A;

int solve(int idx) {
    if (idx == 1)
        return cache[idx] = 1;
    
    int &ret = cache[idx];
    if (ret != -1)
        return ret;
    ret = 1;

    for (int i = idx - 1; i >= 1; i--) {
        if (A[i] < A[idx])
            ret = (ret + solve(i)) % 998244353;
        else
            solve(i);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    A = vector<int>(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    solve(N);

    for (int i = 1; i <= N; i++) {
        cout << cache[i] << " ";
    }
}