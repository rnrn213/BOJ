#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > queens;
vector<bool> c(15, false);
int ans = 0;

int solve(int r) {
    if (r == N) {
        ans += 1;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (c[i]) continue;

        bool valid = true;
        for (int j = queens.size() - 1; j >= 0; j--) {
            int dr = r - queens[j].first;
            if (dr == abs(i - queens[j].second)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            queens.push_back(make_pair(r, i));
            c[i] = true;
            solve(r + 1);
            queens.pop_back();
            c[i] = false;
        }
    }

    return 0;
}

int main() {
    cin >> N;

    // clock_t start, finish;
    // double duration;

    // start = clock();

    solve(0);

    // finish = clock();

    // duration = (double)(finish - start) / CLOCKS_PER_SEC;
    // cout << duration << "\n\n";

    cout << ans;
}