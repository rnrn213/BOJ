#include <bits/stdc++.h>

using namespace std;

int N, k, rooms[201][2], cache[201][201][3];

int solve(int idx, int closed, int prev)
{
    if (idx == N) return (closed == k) ? 0 : -987654321;

    int& ret = cache[idx][closed][prev];
    if (ret != -1) return ret;
    
    if (prev == 0)
        ret = max({rooms[idx][0] + rooms[idx][1] + solve(idx + 1, closed, 0), rooms[idx][1] + solve(idx + 1, closed + 1, 1), rooms[idx][0] + solve(idx + 1, closed + 1, 2)});
    if (prev == 1)
        ret = max(rooms[idx][0] + rooms[idx][1] + solve(idx + 1, closed, 0), rooms[idx][1] + solve(idx + 1, closed + 1, 1));
    if (prev == 2)
        ret = max(rooms[idx][0] + rooms[idx][1] + solve(idx + 1, closed, 0), rooms[idx][0] + solve(idx + 1, closed + 1, 2));

    return ret;
}

int main()
{
    while (true) 
    {   
        cin >> N >> k;
        if (N == 0 && k == 0) break;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < N; i++)
        {
            cin >> rooms[i][0] >> rooms[i][1];
        }

        cout << solve(0, 0, 0) << "\n";
    }
}