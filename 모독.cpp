#include <bits/stdc++.h>

using namespace std;

int N, a[100001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + N + 1);

    long long ans = 0;
    int num = 1;
    for (int i = 1; i <= N; i++)
    {
        if (a[i] - num >= 0)
        {
            ans += a[i] - num;
            num++;
        }
    }

    cout << ans;
}