#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> s(500000), sr(500000, 1);

int find(int x) {
    if (s[x] == x) return x;
    return s[x] = find(s[x]);
}

void merge(int x, int y) {
    x = find(x); y = find(y);

    if (x == y) return;

    if (sr[x] > sr[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    s[y] = x;
    if (sr[x] == sr[y]) sr[y]++;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        s[i] = i;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (find(a) == find(b)) {
            ans = i;
            break;
        }
        merge(a, b);
    }

    cout << ans;
}