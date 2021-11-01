#include <bits/stdc++.h>

using namespace std;

bool isAllSeeAd(vector<bool>& seeAd) {
    for (int i = 1; i < seeAd.size(); i++) {
        if (!seeAd[i])
            return false;
    }

    return true;
}

int solve(int idx, int cnt, const vector< vector<int> >& friendship, vector<bool>& seeAd) {
    if (isAllSeeAd(seeAd)) {
        return cnt;
    }
    if (idx == seeAd.size())
        return seeAd.size() - 1;

    int ret = seeAd.size() - 1;
    ret = min(ret, solve(idx + 1, cnt, friendship, seeAd));
    vector<bool> prevSeeAd = seeAd;
    seeAd[idx] = true;
    for (int i = 0; i < friendship[idx].size(); i++) {
        seeAd[friendship[idx][i]] = true;
    }
    ret = min(ret, solve(idx + 1, cnt + 1, friendship, seeAd));
    seeAd = prevSeeAd;

    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T) {
        int n;
        cin >> n;
        vector< vector<int> > friendship(n + 1);
        for (int i = 1; i <= n; i++) {
            int d;
            cin >> d;
            for (int j = 1; j <= d; j++) {
                int friendNum;
                cin >> friendNum;
                friendship[i].push_back(friendNum);
            }
        }
        vector<bool> seeAd(n + 1, false);

        cout << solve(1, 0, friendship, seeAd) << "\n";

        T--;
    }
}