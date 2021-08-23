#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > route(N + 1, make_pair(0, 0));
    pair<int, int> endPoint = make_pair(0, 0);
    for (int i = 1; i <= N; i++) {
        cin >> route[i].first >> route[i].second;
        endPoint.first += route[i].first;
        endPoint.second += route[i].second;
    }

    cout << endPoint.first << " " << endPoint.second << "\n";

    int minDistance = pow(30001, 2) + pow(30001, 2);
    for (int i = 1; i <= N; i++) {
        int distance = pow(endPoint.first - route[i].first, 2) + pow(endPoint.second - route[i].second, 2);
        if (distance < minDistance) minDistance = distance;
    }

    double ans = round(sqrt(minDistance) * 100) / 100;
    cout << fixed;
    cout.precision(2);
    cout << ans;
}