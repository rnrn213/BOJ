#include <bits/stdc++.h>

using namespace std;

int X, Y, cache[1001][1001];
vector<int> v[1001];

int solve(int x, int y)
{
    int& ret = cache[x][y];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = x + 1; i <= y; i++)
    {
        bool isCoprime = true;
        for (int j = 0; j < v[x].size(); j++)
        {
            if (i % v[x][j] == 0)
            {
                isCoprime = false;
                break;
            }
        }
        if (isCoprime) ret |= !solve(i, y);
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0) v[i].push_back(j);
        }
    }

    cin >> X >> Y;

    if (solve(X, Y)) cout << "khj20006";
    else cout << "putdata";
}