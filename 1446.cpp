#include <bits/stdc++.h>

using namespace std;

int N, D, cache[10001];
vector< pair<int, pair<int, int> > > shortcut;

int solve(int start, int end, int shortcutIdx) {
    
    int &ret = cache[start];
    if (ret != -1)
        return ret;
    ret = end - start;

    for (int i = shortcutIdx; i < N; i++) {
        if (start <= shortcut[i].first && shortcut[i].second.first <= end && shortcut[i].second.first - shortcut[i].first > shortcut[i].second.second) {
            ret = min(ret, shortcut[i].first - start + shortcut[i].second.second + solve(shortcut[i].second.first, end, i + 1));
        }
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;
        shortcut.push_back(make_pair(start, make_pair(end, dist)));
    }
    sort(shortcut.begin(), shortcut.end());

    cout << solve(0, D, 0);
}