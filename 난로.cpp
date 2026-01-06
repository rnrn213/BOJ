#include <bits/stdc++.h>

using namespace std;

int N, K, T[100001], gap[100001];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
        if (i > 0) gap[i - 1] = T[i] - T[i - 1] - 1;
    }

    sort(gap, gap + N - 1);

    int ans = N;
    for (int i = 0; i < N - K; i++)
    {
        ans += gap[i];
    }

    cout << ans;
}
