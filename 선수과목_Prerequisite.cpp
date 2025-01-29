#include <bits/stdc++.h>

using namespace std;

int N, M, cache[500001];
vector<int> p[500001];



int main()
{

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        p[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        if (p[i].size() == 0)
        {
            cache[i] = 1;
        }
        else
        {
            int maxPre = 0;
            for (int j = 0; j < p[i].size(); j++)
            {
                maxPre = (maxPre > cache[p[i][j]]) ? maxPre : cache[p[i][j]];
            }
            cache[i] = 1 + maxPre;
        }

        cout << cache[i] << " ";
    }
}