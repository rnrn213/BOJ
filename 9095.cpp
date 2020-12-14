#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    vector<int> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    for (int i = 4; i < 11; i++) {
        v.push_back(v[i - 1] + v[i - 2] + v[i - 3]);
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }
}