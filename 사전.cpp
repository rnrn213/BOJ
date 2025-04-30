#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000001;

int N, M, K, cache[101][101];

int solve(int a, int z)
{
    if (a == 0 && z == 0) return 1;

    int& ret = cache[a][z];
    if (ret != -1) return ret;
    ret = 0;

    if (a > 0)
        ret += solve(a - 1, z);
    if (z > 0)
        ret += solve(a, z - 1);

    return ret = (ret >= INF) ? INF : ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cache[0][0] = 1;

    cin >> N >> M >> K;

    if (solve(N, M) < K) cout << -1;
    else
    {
        int a = N, z = M;
        string ans = "";
        while (a > 0 || z > 0)
        {
            if (a > 0)
            {
                if (cache[a - 1][z] >= K)
                {
                    ans += "a";
                    a--;
                    continue;
                }
                else
                {
                    K -= cache[a - 1][z];
                }
            }
            if (z > 0)
            {
                if (cache[a][z - 1] >= K)
                {
                    ans += "z";
                    z--;
                    continue;
                }
            }
        }
        cout << ans;
    }
}