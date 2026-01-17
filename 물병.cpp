#include <bits/stdc++.h>

using namespace std;

int N, K;
priority_queue<int> pq;

int main()
{
    cin >> N >> K;

    int num = 1;
    for (int i = N; i > 0; i /= 2)
    {
        if (i % 2 == 1) pq.push(-num);
        num *= 2;
    }

    int ans = 0;
    while (pq.size() > K)
    {
        int w = -pq.top();
        pq.pop();
        int next = -pq.top();
        pq.pop();
        ans += next - w;
        pq.push(-next * 2);
    }

    cout << ans;
}
