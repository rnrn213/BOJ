#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C, T;
    cin >> R >> C;
    vector< vector<int> > I(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> I[i][j];
        }
    }
    cin >> T;

    int cnt = 0;
    for (int j = 0; j <= C - 3; j++) {
        for (int i = 0; i <= R - 3; i++) {
            vector<int> filter;
            for (int n = 0; n < 3; n++) {
                for (int m = 0; m < 3; m++) {
                    filter.push_back(I[i + n][j + m]);
                }
            }
            sort(filter.begin(), filter.end());
            if (filter[4] >= T) cnt++;
        }
    }
    cout << cnt;
}