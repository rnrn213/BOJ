#include <bits/stdc++.h>

using namespace std;

string A, B;
int dp[1000][1000];

int solve(int a, int b)
{
    if (a == A.size()) return B.size() - b;
    if (b == B.size()) return A.size() - a;
    

    int& ret = dp[a][b];
    if (ret != -1) return ret;
    ret = 0;

    if (A[a] == B[b]) ret = solve(a + 1, b + 1);
    else
    {
        ret = 1 + min({solve(a, b + 1), solve(a + 1, b), solve(a + 1, b + 1)});
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> A >> B;
    
    cout << solve(0, 0);
}