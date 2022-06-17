#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> u, pair<int, int> v) {
    if (u.second == v.second)
        return u.first < v.first;
    return u.second < v.second;
}

int main() {
    int N;
    cin >> N;

    vector< pair<int, int> > meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int minStart = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= minStart) {
            cnt++;
            minStart = meetings[i].second;
        }
    }

    cout << cnt;
}