#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    vector< pair<int, int> > v;
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));
    for (int i = 2; i <= 40; i++) {
        v.push_back(make_pair(v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second));
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << v[N].first << " " << v[N].second << '\n';
    }
}