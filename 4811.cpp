#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[31][31];

long long solve(int w, int h) {
    if (w == 0 && h == 0) return 1;

    long long &ret = cache[w][h];
    if (ret != -1) return ret;
    ret = 0;

    if (w > 0)
        ret += solve(w - 1, h + 1);
    if (h > 0)
        ret += solve(w, h - 1);

    return ret;
}

int main() {
    while (true) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        if (N == 0) break;

        cout << solve(N, 0) << "\n";
    }
}