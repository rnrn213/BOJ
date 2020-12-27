#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int K;
    cin >> K;

    vector< pair<int, int> > v;
    v.push_back(make_pair(1, 0));
    for (int i = 1; i <= K; i++) {
        v.push_back(make_pair(v[i - 1].second, v[i - 1].first + v[i - 1].second));
    }
    cout << v[K].first << " " << v[K].second;
}