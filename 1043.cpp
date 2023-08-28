#include <bits/stdc++.h>

using namespace std;

int N, M, cnt = 0;
vector<bool> know(51, false);
vector<int> party[50];

int main() {
    cin >> N >> M;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        know[p] = true;
    }

    queue<int> q;
    vector<bool> visited(M, false);
    for (int i = 0; i < M; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int p;
            cin >> p;
            party[i].push_back(p);
        }
        for (int j = 0; j < sz; j++) {
            if (know[party[i][j]]) {
                q.push(i);
                visited[i] = true;
                break;
            }
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < party[idx].size(); i++) {
            int p = party[idx][i];
            if (!know[p]) {
                know[p] = true;

                for (int j = 0; j < M; j++) {
                    if (!visited[j]) {
                        for (int k = 0; k < party[j].size(); k++) {
                            if (party[j][k] == p) {
                                q.push(j);
                                visited[j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << M - cnt;
}