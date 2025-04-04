#include <bits/stdc++.h>

using namespace std;

string A, B;
int aSize, bSize, cache[1001][1001];

int solve(int aIdx, int bIdx)
{
    if (aIdx == aSize && bIdx == bSize) return 0;

    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 12345;

    if ((aIdx < aSize && bIdx < bSize) && A[aIdx] == B[bIdx])
        ret = min(ret, 1 + solve(aIdx + 1, bIdx + 1));
    if (aIdx < aSize)
        ret = min(ret, 1 + solve(aIdx + 1, bIdx));
    if (bIdx < bSize)
        ret = min(ret, 1 + solve(aIdx, bIdx + 1));

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> A >> B;
    aSize = A.size();
    bSize = B.size();

    cout << solve(0, 0);
}