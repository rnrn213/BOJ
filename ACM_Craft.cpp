#include <bits/stdc++.h>

using namespace std;

int T, N, K, D[1001], cache[1001];
vector<vector<int>> v;

int solve(int idx)
{
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = D[idx];

    for (int i = 0; i < v[idx].size(); i++)
    {
        ret = max(ret, D[idx] + solve(v[idx][i]));
    }

    return ret;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> N >> K;
        v = vector<vector<int>>(N + 1, vector<int>());
        for (int i = 1; i <= N; i++)
        {
            cin >> D[i];
        }
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            v[Y].push_back(X);
        }
        int W;
        cin >> W;
        
        cout << solve(W) << "\n";
    }
}