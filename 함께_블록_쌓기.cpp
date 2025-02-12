#include <bits/stdc++.h>

using namespace std;

int N, M, H, cache[51][1001];
vector<vector<int>> v(50);

int solve(int idx, int height)
{
    if (height == H) return 1;
    if (idx == N) return 0;

    int& ret = cache[idx][height];
    if (ret != -1) return ret;
    ret = solve(idx + 1, height);

    for (int i = 0; i < v[idx].size(); i++)
    {
        if (height + v[idx][i] <= H)
            ret = (ret + solve(idx + 1, height + v[idx][i])) % 10007;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> N; iss >> M; iss >> H;
    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        istringstream iss(line);
        int num;
        while (iss >> num)
        {
            v[i].push_back(num);
        }
    }

    cout << solve(0, 0);
}