#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, S, R;
    cin >> N >> S >> R;
    vector< pair<int, int> > teams(N, make_pair(0, 0));

    for (int i = 0; i < S; i++) {
        int t;
        cin >> t;
        teams[t-1].first = 1;
    }

    for (int i = 0; i < R; i++) {
        int t;
        cin >> t;
        teams[t-1].second = 1;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (teams[i].first == 1) {
            if (teams[i].second == 1) {
                teams[i].first = teams[i].second = 0;
            }
            else if (i > 0 && teams[i-1].first == 0 && teams[i-1].second == 1) {
                teams[i].first = teams[i-1].second = 0;
            }
            else if (i < N - 1 && teams[i+1].first == 0 && teams[i+1].second == 1) {
                teams[i].first = teams[i+1].second = 0;
            }
        }

        if (teams[i].first == 1)
            cnt++;
    }
    
    cout << cnt;
}