#include <bits/stdc++.h>

using namespace std;

int K, cnt[5];

int main()
{
    cin >> K;
    vector<pair<int, int>> v;
    for (int i = 0; i < 6; i++)
    {
        int n, m;
        cin >> n >> m;
        v.push_back(make_pair(n, m));
        cnt[n]++;
    }

    int bigArea = 1, smallArea = 1;
    for (int i = 0; i < 6; i++)
    {
        if (cnt[v[i].first] == 1)
        {
            bigArea *= v[i].second;
            int beforeIdx = (i - 1 + 6) % 6;
            if (cnt[v[beforeIdx].first] == 2)
                smallArea *= v[(beforeIdx - 1 + 6) % 6].second;
            int nextIdx = (i + 1) % 6;
            if (cnt[v[nextIdx].first] == 2)
                smallArea *= v[(nextIdx + 1) % 6].second;
        }
    }
    cout << (bigArea - smallArea) * K;
}