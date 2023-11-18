#include <bits/stdc++.h>

using namespace std;

int T, K;

int main() {
    cin >> T;
    while (T--) {
        cin >> K;
        priority_queue<long long> pq;
        for (int i = 0; i < K; i++) {
            long long n;
            cin >> n;
            pq.push(-1 * n);
        }

        long long ans = 0;
        while (pq.size() > 1) {
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();

            pq.push(n1 + n2);
            ans += n1 + n2;
        }

        cout << -1 * ans << '\n';
    }
}