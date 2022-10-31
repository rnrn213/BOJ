#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[101];

long long solve(int btn) {
    if (btn <= 6) return btn;

    long long& ret = cache[btn];
    if (ret != -1) return ret;

    ret = solve(btn - 1) + 1;
    ret = max(ret, solve(btn - 3) * 2);
    ret = max(ret, solve(btn - 4) * 3);
    ret = max(ret, solve(btn - 5) * 4);

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> N;

    cout << solve(N);
}