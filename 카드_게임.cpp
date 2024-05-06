#include <bits/stdc++.h>

using namespace std;

int T, N, cards[1000], dp[1001][1001];

int solve(int left, int right, int turn)
{
    if (left == right) return 0;

    int& ret = dp[left][right];
    if (ret != -1) return ret;
    ret = 0;

    if (turn % 2 == 0) ret = max(cards[left] + solve(left + 1, right, turn + 1), cards[right - 1] + solve(left, right - 1, turn + 1));
    else ret = min(solve(left + 1, right, turn + 1), solve(left, right - 1, turn + 1));

    return ret;
}

int main()
{
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(dp, -1, sizeof(dp));

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> cards[i];
        }

        cout << solve(0, N, 0) << "\n";
    }
}