#include <bits/stdc++.h>

using namespace std;

int N, tree[50];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    int d;
    cin >> d;

    tree[d] = -2;
    queue<int> q;
    q.push(d);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (tree[i] == node) {
                q.push(i);
                tree[i] = -2;
            }
        }
    }

    int cnt[50] = {0, }, ans = 0;
    for (int i = 0; i < N; i++) {
        if (tree[i] >= 0)
            cnt[tree[i]]++;
        else if (tree[i] == -2)
            cnt[i] = -1;
    }
    for (int i = 0;  i< N; i++) {
        if (cnt[i] == 0)
            ans++;
    }

    cout << ans;
}