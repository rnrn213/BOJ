#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N, count = 0;
    cin >> N;

    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    for (int i = 4; i <= N; i++) {
        if (i % 3 == 0) {
            if (i % 2 == 0) {
                int minValue = min({v[i / 3], v[i / 2], v[i - 1]});
                v.push_back(minValue + 1);
            }
            else {
                int minValue = min(v[i / 3], v[i - 1]);
                v.push_back(minValue + 1);
            }
        }
        else if (i % 2 == 0) {
            int minValue = min(v[i / 2], v[i - 1]);
            v.push_back(minValue + 1);
        }
        else {
            v.push_back(v[i - 1] + 1);
        }
    }

    cout << v[N];
}