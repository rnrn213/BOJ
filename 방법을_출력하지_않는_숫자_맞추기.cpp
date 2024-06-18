#include <bits/stdc++.h>

using namespace std;

int N, dp[10001][11];
string num, ans;

int solve(int idx, int left)
{
    if (idx == N) return 0;

    int& ret = dp[idx][left % 10];
    if (ret != -1) return ret;
    
    int x = (num[idx] - '0' + (left % 10)) % 10;
    int diff = ans[idx] - '0' - x;

    return ret = min(((10 - diff) % 10) + solve(idx + 1, left), ((diff + 10) % 10) + solve(idx + 1, left + ((diff + 10) % 10)));
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N >> num >> ans;

    cout << solve(0, 0);
}