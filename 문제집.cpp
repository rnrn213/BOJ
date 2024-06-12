#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v(32001, 0), vv[32001];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        vv[A].push_back(B);
        v[B]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= N; i++)
    {
        if (v[i] == 0) pq.push(-i);
    }

    while (!pq.empty())
    {
        int num = -pq.top();
        pq.pop();

        cout << num << " ";

        for (int i = 0; i < vv[num].size(); i++)
        {
            v[vv[num][i]]--;
            if (v[vv[num][i]] == 0) pq.push(-vv[num][i]);
        }
    }
}