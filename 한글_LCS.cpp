#include <bits/stdc++.h>

using namespace std;

int cache[1001][1001], aSize, bSize;
string A, B;
wstring wstrA, wstrB;

int solve(int aIdx, int bIdx)
{
    if (aIdx == aSize && bIdx == bSize) return 0;

    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 0;

    if ((aIdx < aSize && bIdx < bSize) && (wstrA[aIdx] == wstrB[bIdx]))
    {
        ret = 1 + solve(aIdx + 1, bIdx + 1);
    }
    else 
    {
        if (aIdx < aSize) ret = max(ret, solve(aIdx + 1, bIdx));
        if (bIdx < bSize) ret = max(ret, solve(aIdx, bIdx + 1));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> A >> B;
    wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    wstrA = converter.from_bytes(A);
    wstrB = converter.from_bytes(B);
    aSize = wstrA.size();
    bSize = wstrB.size();

    cout << solve(0, 0);
}