#include <bits/stdc++.h>

using namespace std;

int N, K, c[300000];
vector< pair<int, int> > gap;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        if (i != 0) gap.push_back(make_pair(c[i] - c[i - 1], i - 1));
    }

    sort(gap.begin(), gap.end());

    int ans = 0;
    for (int i = N; i > K; i--) {
        ans += gap[N - i].first;
    }
    
    cout << ans;
}