#include <bits/stdc++.h>

using namespace std;

bool cmp(pair< pair<int, int>, string> u, pair< pair<int, int>, string> v) {
    if (u.first.first == v.first.first) {
        return u.first.second < v.first.second;
    }
    else {
        return u.first.first < v.first.first;
    }
}
int main() {
    int N;
    cin >> N;
    vector< pair< pair<int, int>, string> > users(N);
    vector<int> cnt(201, 0);
    for (int i = 0; i < N; i++) {
        cin >> users[i].first.first >> users[i].second;
        users[i].first.second = cnt[users[i].first.first]++;
    }

    sort(users.begin(), users.end(), cmp);

    for (auto user: users) {
        cout << user.first.first << " " << user.second << "\n";
    }
}