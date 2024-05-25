#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

string s;
int dp[2501];

bool isPalindrome(int left, int right)
{
    while (left <= right)
    {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int solve(int idx)
{
    if (idx == s.size()) return 0;

    int& ret = dp[idx];
    if (ret != -1) return ret;
    ret = INF;

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(idx, i))
        {
            ret = min(ret, 1 + solve(i + 1));
        }
        else
        {
            ret = min(ret, i - idx + 1 + solve(i + 1));
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> s;

    cout << solve(0);
}