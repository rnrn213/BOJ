#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> u, pair<int, int> v) {
    if (u.first == v.first)
        return u.second < v.second;
    
    return u.first < v.first;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector< pair<int, int> > points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end(), cmp);

    for (auto point: points) {
        cout << point.first << " " << point.second << "\n";
    }
}