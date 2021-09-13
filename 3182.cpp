#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> seniors(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> seniors[i];
    }

    int ans, maxCnt = 0;
    for (int i = 1; i <= N; i++) {
        vector<bool> visited(N + 1, false);

        int idx = i, cnt = 1;
        while (!visited[idx]) {
            visited[idx] = true;
            idx = seniors[idx];
            cnt++;
        }

        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans = i;
        }
    }

    cout << ans;
}