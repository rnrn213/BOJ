#include <bits/stdc++.h>

using namespace std;

int N, cache[51];
vector<int> v[51];

int solve(int idx)
{
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 0;

    vector<int> temp;
    for (int i = 0; i < v[idx].size(); i++)
    {
        temp.push_back(solve(v[idx][i]));
    }
    sort(temp.begin(), temp.end(), greater<>());

    if (temp.size() > 0)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            ret = max(ret, i + 1 + temp[i]);
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
        int num;
        cin >> num;
        if(num == -1) continue;
        v[num].push_back(i);
    }

    cout << solve(0);
}