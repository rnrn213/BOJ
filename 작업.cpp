#include <bits/stdc++.h>

using namespace std;

int N, cache[10001];

int main()
{
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        int num, prevMax = 0;
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            int prev;
            cin >> prev;
            prevMax = max(prevMax, cache[prev]);
        }

        cache[i] = t + prevMax;
        ans = max(ans, cache[i]);
    }

    cout << ans;
}