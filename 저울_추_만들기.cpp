#include <bits/stdc++.h>

using namespace std;

int n, ans[10001];
vector<int> v;

int main()
{
    int num = 2;
    while (num < 20000)
    {
        v.push_back(num);
        num *= 2;
    }

    cin >> n;
    for (int i = n; i > 0; i--)
    {
        if (ans[i] != 0) continue;
        int idx = v.size() - 1;
        for (int j = n; j > 0; j--)
        {
            if (ans[j] != 0) continue;
            while (idx >= 0 && i + j < v[idx]) idx--;

            if (i + j == v[idx])
            {
                ans[i] = j;
                ans[j] = i;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
}