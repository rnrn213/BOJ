#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< vector<int> > dot(N + 1);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        dot[y].push_back(x);
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (dot[i].size() == 0) continue;

        sort(dot[i].begin(), dot[i].end());

        sum += dot[i][1] - dot[i][0];
        for (int j = 1; j < dot[i].size() - 1; j++) {
            sum += min(dot[i][j] - dot[i][j - 1], dot[i][j + 1] - dot[i][j]);
        }
        sum += dot[i][dot[i].size() - 1] - dot[i][dot[i].size() - 2];
    }

    cout << sum;
}