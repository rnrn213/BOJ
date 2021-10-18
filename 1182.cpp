#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> arr;

int solve(int idx, int sum) {
    int ret = 0;

    if (sum == S)
        ret++;
    if (idx == N - 1)
        return ret;
    
    for (int i = idx + 1; i < N; i++) {
        ret += solve(i, sum + arr[i]);
    }

    return ret;
}

int main() {
    cin >> N >> S;
    arr = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += solve(i, arr[i]);
    }

    cout << ans;
}