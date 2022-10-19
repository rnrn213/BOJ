#include <bits/stdc++.h>

using namespace std;

int N, num[100];
long long cache[100][21];

long long solve(int idx, int value) {
    if (value < 0 || value > 20)
        return 0;
    if (idx == N - 1) {
        if (value == num[N - 1])
            return 1;
        else 
            return 0;
    }
    
    long long& ret = cache[idx][value];
    if (ret != -1)
        return ret;
    ret = 0;
    return ret += solve(idx + 1, value - num[idx]) + solve(idx + 1, value + num[idx]);
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    cout << solve(1, num[0]);
}