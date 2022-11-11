#include <bits/stdc++.h>

using namespace std;

int N, cache[1000001], path[1000001];

int solve(int num) {
    if (num == 1) return 0;

    int& ret = cache[num];
    if (ret != -1) return ret;
    ret = 123456789;

    if (num % 3 == 0) {
        ret = 1 + solve(num / 3);
        path[num] = num / 3;
    }

    if ((num % 2 == 0) && ret > 1 + solve(num / 2)) {
        ret = 1 + solve(num / 2);
        path[num] = num / 2;
    }

    if (ret > 1 + solve(num - 1)) {
        ret = 1 + solve(num - 1);
        path[num] = num - 1;
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    memset(path, 0, sizeof(path));

    cin >> N;

    cout << solve(N) << "\n";

    while (N > 0) {
        cout << N << " ";
        N = path[N];
    }
}