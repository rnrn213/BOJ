#include <bits/stdc++.h>

using namespace std;

int N, K, arr[30][3], dp[31][31][31][451];
string temp = "", ans = "";

int solve(int idx, int A, int B, int k)
{
    if (idx == N)
    {
        if (k == 0)
        {
            ans = temp;
            return 1;
        }
        return 0;
    }
    if (k < 0) return 0;

    int& ret = dp[idx][A][B][k];
    if (ret != -1) return ret;
    ret = 0;

    temp += "A";
    ret = max(ret, solve(idx + 1, A + 1, B, k));
    temp.pop_back();

    temp += "B";
    ret = max(ret, solve(idx + 1, A, B + 1, k - A));
    temp.pop_back();

    temp += "C";
    ret = max(ret, solve(idx + 1, A, B, k - A - B));
    temp.pop_back();

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N >> K;

    solve(0, 0, 0, K);

    if (ans.size() == 0) cout << -1;
    else cout << ans;
}