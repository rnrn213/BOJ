#include <bits/stdc++.h>

using namespace std;

int dp[41][41][41], aSize, bSize;
string A, B, ans = "";
vector<char> pwd(41, '.');
vector<int> len(41, 0);

int solve(int aIdx, int bIdx, int pwdIdx)
{
    if (aIdx == aSize || bIdx == bSize)
    {

        return 0;
    }

    int& ret = dp[aIdx][bIdx][pwdIdx];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = aIdx; i < aSize; i++)
    {
        for (int j = bIdx; j < bSize; j++)
        {
            if (A[i] == B[j])
            {
                int temp = 1 + solve(i + 1, j + 1, pwdIdx + 1);
                if (temp > len[pwdIdx])
                {
                    pwd[pwdIdx] = A[i];
                    len[pwdIdx] = temp;
                    ret = temp;
                }
            }
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> A >> B;
    aSize = A.size();
    bSize = B.size();

    solve(0, 0, 0);

    for (char c : pwd)
    {
        if (c == '.') break;
        cout << c;
    }
}