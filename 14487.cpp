#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> dist(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    sort(dist.begin(), dist.end());

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += dist[i];
    }

    cout << sum;
}