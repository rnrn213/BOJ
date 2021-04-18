#include <bits/stdc++.h>

using namespace std;

int n, cache[100000];
vector<int> v;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

void initCache() {
    memset(cache, -1, 100000 * sizeof(int));
}

int solve(int index) {
    if (index == n) return -1000000000;

    int& ret = cache[index];
    if (ret != -1) return ret;
    return ret = max(v[index], v[index] + solve(index + 1));
}

void output() {
    sort(cache, cache + n, greater<int>());
    cout << cache[0];
}

int main() {
    input();
    initCache();
    solve(0);
    output();
}