#include <bits/stdc++.h>

using namespace std;

vector< vector<bool> > networks(101, vector<bool>(101, false));
vector<bool> isVisited(101, false);

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        networks[a][b] = networks[b][a] = true;
    }

    queue<int> q;
    q.push(1);
    isVisited[1] = true;
    int cnt = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cnt++;

        for (int i = 1; i <= n; i++) {
            if (!isVisited[i] && networks[c][i] == true) {
                q.push(i);
                isVisited[i] = true;
            }
        }
    }

    cout << cnt - 1;
}