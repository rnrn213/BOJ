#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int N;
        cin >> N;

        vector< pair<int, int> > v;
        for (int i = 1; i <= sqrt(N); i++) {
            if (N % i == 0) {
                int j = N / i;
                int a = (j - i) / 2, b = (i + j) / 2;
                if ((b - a) * (b + a) == N) {
                    v.push_back(make_pair(a, b));
                }
            }
        }
        sort(v.begin(), v.end());

        if (v.size() == 0)
            cout << "IMPOSSIBLE\n";
        else
            cout << v[0].first << " " << v[0].second << "\n";

        T--;
    }
}