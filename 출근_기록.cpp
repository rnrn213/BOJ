#include <bits/stdc++.h>

using namespace std;

int N, dp[51][51][51][2][3];
string S;
vector<char> temp(51), ans;
vector<int> cnt(3, 0);

int solve(int A, int B, int C, int prevB, int prevC)
{
    if (A == 0 && B == 0 && C == 0)
    {
        ans = temp;
        return 1;
    }

    int& ret = dp[A][B][C][prevB][prevC];
    if (ret != -1) return ret;
    ret = 0;

    int idx = N - A - B - C;
    if (prevC == 0)
    {
        if (A > 0)
        {
            temp[idx] = 'A';
            ret = max(ret, solve(A - 1, B, C, 0, prevC));
        }
        if (prevB == 0 && B > 0)
        {
            temp[idx] = 'B';
            ret = max(ret, solve(A, B - 1, C, 1, prevC));
        }
        if (C > 0)
        {
            temp[idx] = 'C';
            ret = max(ret, solve(A, B, C - 1, 0, 1));
        }
    }
    else
    {
        if (A > 0)
        {
            temp[idx] = 'A';
            ret = max(ret, solve(A - 1, B, C, 0, (prevC + 1) % 3));
        }
        if (prevB == 0 && B > 0)
        {
            temp[idx] = 'B';
            ret = max(ret, solve(A, B - 1, C, 1, (prevC + 1) % 3));
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    

    cin >> S;
    N = S.size();
    for (char c : S)
    {
        if (c == 'A') cnt[0]++;
        if (c == 'B') cnt[1]++;
        if (c == 'C') cnt[2]++;
    }

    solve(cnt[0], cnt[1], cnt[2], 0, 0);

    if (ans.size() == 0) cout << -1;
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << ans[i];
        }
    }
}