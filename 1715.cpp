#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> pq;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(-num);
    }

    int ans = 0;
    while (pq.size() > 1)
    {
        int A = -pq.top();
        pq.pop();
        int B = -pq.top();
        pq.pop();

        ans += A + B;
        pq.push(-(A + B));
    }

    cout << ans;
}