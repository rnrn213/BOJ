#include <bits/stdc++.h>

using namespace std;

int ASize, BSize, cache[1000][1000];
string A, B;

int solve(int aIdx, int bIdx) {
    if (aIdx == ASize || bIdx == BSize) return 0;

    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 0;

    if (A[aIdx] == B[bIdx]) ret = 1 + solve(aIdx + 1, bIdx + 1);
    
    return ret = max({ret, solve(aIdx + 1, bIdx), solve(aIdx, bIdx + 1)});
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> A >> B;
    ASize = A.size();
    BSize = B.size();

    cout << solve(0, 0);
}