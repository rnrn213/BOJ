#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

void solve() {
    queue<long long> q;
    for (int i = 0; i < 10; i++) {
        q.push(i);
        v.push_back(i);
    }

    while (!q.empty()) {
        queue<long long> nextQ;
        while (!q.empty()) {
            long long n = q.front();
            q.pop();
            
            long long f = 0, tempN = n;
            int m = (n == 0) ? 1 : 0;
            while (tempN) {
                f = tempN;
                tempN /= 10;
                m++;
            }

            for (int i = f + 1; i < 10; i++) {
                long long nextNum = n + i * pow(10, m);
                nextQ.push(nextNum);
                v.push_back(nextNum);
            }
        }
        q = nextQ;
    }
}

int main() {
    int N;
    cin >> N;

    solve();

    sort(v.begin(), v.end());

    if (N >= v.size()) cout << -1;
    else cout << v[N];
}