#include <bits/stdc++.h>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    queue<long long> q;
    q.push(A);
    int opCnt = 1, ans = -1;
    while (!q.empty()) {
        queue<long long> nextQ;

        while (!q.empty()) {
            long long n = q.front();
            q.pop();

            if (n == B) {
                ans = opCnt;
                while (!q.empty()) {
                    q.pop();
                }
                while (!nextQ.empty()) {
                    nextQ.pop();
                }
            }

            if (n * 2 <= B)
                nextQ.push(n * 2);
            if (n * 10 + 1 <= B)
                nextQ.push(n * 10 + 1);
        }

        q = nextQ;
        opCnt++;
    }

    cout << ans;
}