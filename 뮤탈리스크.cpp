#include <bits/stdc++.h>

using namespace std;

int N, cache[61][61][61];
vector<int> SCV(3, 0);

int solve(vector<int> SCV)
{
    if (SCV[0] == 0 && SCV[1] == 0 && SCV[2] == 0) return 0;

    int& ret = cache[SCV[0]][SCV[1]][SCV[2]];
    if (ret != -1) return ret;
    ret = 2100000000;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j) continue;
            for (int k = 0; k < 3; k++)
            {
                if (i == k || j == k) continue;
                vector<int> temp = SCV;
                temp[i] = (temp[i] - 9 > 0) ? temp[i] - 9 : 0;
                temp[j] = (temp[j] - 3 > 0) ? temp[j] - 3 : 0;
                temp[k] = (temp[k] - 1 > 0) ? temp[k] - 1 : 0;
                ret = min(ret, 1 + solve(temp));
            }
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> SCV[i];
    }

    cout << solve(SCV);
}