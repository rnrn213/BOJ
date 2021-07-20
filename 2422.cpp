#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > ddong(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ddong[a].push_back(b);
        ddong[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            if (find(ddong[i].begin(), ddong[i].end(), j) != ddong[i].end()) {
                continue;
            }
            for (int k = j + 1; k <= N; k++) {
                if (find(ddong[i].begin(), ddong[i].end(), k) == ddong[i].end() && 
                    find(ddong[j].begin(), ddong[j].end(), k) == ddong[j].end()) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}