#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 100000000;
vector< pair<int, int> > houses, chickens;
vector<bool> visited(13, true), cache(8193, false);

int getCd() {
    int ret = 0;
    for (int i = 0; i < houses.size(); i++) {
        int cd = 10000;
        for (int j = 0; j < chickens.size(); j++) {
            if (visited[j]) {
                int d = abs(houses[i].first - chickens[j].first) +
                        abs(houses[i].second - chickens[j].second);
                if (d < cd)
                    cd = d;
            }
        }
        ret += cd;
    }
    return ret;
}

int solve(int r, int a) {
    if (cache[a]) return 0;
    cache[a] = true;
    if (chickens.size() - r == M) {
        int cd = getCd();
        if (cd < ans)
            ans = cd;
        
        return 0;
    }

    for (int i = 0; i < chickens.size(); i++) {
        if (visited[i]) {
            visited[i] = false;
            solve(r + 1, a + (1 << i));
            visited[i] = true;
        }
    }

    return 0;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;

            if (num == 1)
                houses.push_back(make_pair(i, j));
            if (num == 2)
                chickens.push_back(make_pair(i, j));
        }
    }

    solve(0, 0);

    cout << ans;
}