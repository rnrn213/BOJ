#include <bits/stdc++.h>

using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long solve(long long x) {
    if (x == 0)
        return 1;

    if (m.find(x) != m.end()) {
        return m.find(x)->second;
    }

    long long value = solve(x / P) + solve(x / Q);
    m.insert({x, value});

    return value;
}

int main() {
    cin >> N >> P >> Q;

    cout << solve(N);
}