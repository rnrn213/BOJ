#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    vector<long long> v = {0, 1, 1};

    int N;
    cin >> N;
    
    if (N > 2) {
        for (int i = 3; i <= N; i++) {
            v.push_back(v[i - 1] + v[i - 2]);
        }
    }

    cout << 2 * v[N] + 2 * (v[N - 1] + v[N]);
}