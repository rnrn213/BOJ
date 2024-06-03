#include <bits/stdc++.h>

using namespace std;

int N, Q, U, V, K[1001], pSum[1001], dp[1001][1001];

int solve(int left, int right)
{
    if (left == right) return U * K[left];

    int& ret = dp[left][right];
    if (ret != -1) return ret;
    ret = U * (pSum[right] - pSum[left - 1]) + V * (right - left);

    return ret = max({ret, solve(left + 1, right), solve(left, right - 1)});
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> N >> Q >> U >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i];
        pSum[i] = K[i] + pSum[i - 1];
    }

    for (int i = 0; i < Q; i++)
    {
        int C, A, B;
        cin >> C >> A >> B;

        if (C == 0)
        {
            cout << solve(A, B) << "\n";
        }
        if (C == 1)
        {
            memset(dp, -1, sizeof(dp));
            int diff = B - K[A];
            K[A] = B;
            for (int j = A; j <= N; j++)
            {
                pSum[j] += diff;
            }
        }
    }
}