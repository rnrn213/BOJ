#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N, A[4001], P[4001];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }

        sort(A + 1, A + 1 + N);

        for (int i = 1; i <= N; i++)
        {
            P[i] = P[i - 1] + A[i];
        }

        ll ans = 0;
        for (int i = 1; i < N; i++)
        {
            int cost = 2100000000;
            for (int j = 1; j + i <= N; j++)
            {
                cost = min(cost, A[j + i] * (i + 1) - (P[j + i] - P[j - 1]));
            }
            ans += cost;
        }
        cout << ans << "\n";
    }
}
