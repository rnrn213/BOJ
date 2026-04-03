#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1000000000000000;

int T, N, K;
ll a, b, S[101], cache[101][10001];

ll solve(int idx, int L)
{
    if (L >= K) return 0;
    if (idx == N) return INF;

    ll& ret = cache[idx][L];
    if (ret != -1) return ret;

    return ret = min(a * (S[idx] - 1) * (S[idx] - 1) + b + solve(idx + 1, L + S[idx]), solve(idx + 1, L));
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> N >> K >> a >> b;
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        }

        sort(S, S + N);
        int start = 0;
        while (S[start] == 1)
        {
            K--;
            start++;
        }

        if (start == N) cout << 0 << "\n";
        else cout << solve(start, 0) << "\n";
    }
}