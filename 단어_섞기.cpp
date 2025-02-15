#include <bits/stdc++.h>

using namespace std;

int N, cache[201][201], aSize, bSize;
string a, b, c;

int solve(int aIdx, int bIdx)
{
    if (aIdx == aSize && bIdx == bSize) return 1;

    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 0;

    if (aIdx < aSize && a[aIdx] == c[aIdx + bIdx])
        ret |= solve(aIdx + 1, bIdx);
    if (bIdx < bSize && b[bIdx] == c[aIdx + bIdx])
        ret |= solve(aIdx, bIdx + 1);

    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        memset(cache, -1, sizeof(cache));

        cin >> a >> b >> c;
        aSize = a.size();
        bSize = b.size();
        
        if (solve(0, 0) == 1)
            cout << "Data set " << i << ": yes\n";
        else
            cout << "Data set " << i << ": no\n"; 
    }
}