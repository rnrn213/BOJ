#include <bits/stdc++.h>

using namespace std;

int M, K, cache[5001][1000], pSize;
vector<int> p;
bool isP[5001];

void getIsP()
{
    for (int i = 1; i <= 5000; i++)
    {
        string s = to_string(i);
        int sum = 0;
        for (int j = 0; j < s.size(); j++)
        {
            sum += s[j] - '0';
        }

        if (i % sum == 0) p.push_back(i);
    }
    pSize = p.size();
}

int solve(int num, int idx)
{
    if (num == 0) return 1;

    int& ret = cache[num][idx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = idx; i >= 0; i--)
    {
        if (num - p[i] < 0) continue;
        ret = (ret + solve(num - p[i], i)) % K;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    memset(isP, 0, sizeof(isP));

    cin >> M >> K;

    getIsP();

    cout << solve(M, pSize - 1);
}