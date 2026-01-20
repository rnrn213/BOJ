#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(-10000) * 1000 * 1000 - 1;

int n, L, J[1001];
long long cache[1001], price = 0;
vector< pair<int, int> > v;

long long solve(int idx)
{
    if (idx > L) return 0;

    long long& ret = cache[idx];
    if (ret != INF) return ret;

    return ret = max((long long)J[idx], J[idx] + solve(idx + 1));
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> L;
        for (int i = 1; i <= L; i++)
        {
            cache[i] = INF;
            cin >> J[i];
        }

        solve(1);
        
        int start = -1, size = -1;
        long long ans = INF;
        for (int i = 1; i <= L; i++)
        {
            if (ans == cache[i])
            {
                int cnt = 0, sum = 0, k = i;
                cnt = (sum == ans && J[i] == 0) ? 1 : 0;
                while (sum != ans && k <= L)
                {
                    sum += J[k];
                    cnt++;
                    k++;
                }
                if (cnt < size)
                {
                    start = i;
                    size = cnt;
                }
            }
            else if (ans < cache[i])
            {
                ans = cache[i];
                int cnt = 0, sum = 0, k = i;
                cnt = (sum == ans && J[i] == 0) ? 1 : 0;
                while (sum != ans && k <= L)
                {
                    sum += J[k];
                    cnt++;
                    k++;
                }
                start = i;
                size = cnt;
            }
        }

        price += ans;
        v.push_back(make_pair(start, start + size - 1));
    }

    cout << price << "\n";
    for (auto p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }
}
