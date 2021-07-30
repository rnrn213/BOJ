#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }

    long long ans = 10000000000;
    pair<int, int> ansAB;
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            long long RSS = 0;
            for (int i = 0; i < N; i++) {
                RSS += pow(students[i].second - (a * students[i].first + b), 2);
            }
            if (ans > RSS) {
                ansAB = make_pair(a, b);
                ans = RSS;
            }
        }
    }
    cout << ansAB.first << " " << ansAB.second;
}