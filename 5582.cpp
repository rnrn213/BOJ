#include <bits/stdc++.h>

using namespace std;

string A, B;
int cache[4000][4000];

int solve(int aIdx, int bIdx) {
    if (aIdx == A.size() || bIdx == B.size())
        return 0;
    
    int& ret = cache[aIdx][bIdx];
    if (ret != -1)
        return ret;
    ret = 0;

    if (A[aIdx] == B[bIdx]) {
        ret = 1 + solve(aIdx + 1, bIdx + 1);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    
    cin >> A >> B;

    int ans = 0, aSize = A.size(), bSize = B.size();
    for (int aIdx = 0; aIdx < aSize; aIdx++) {
        for (int bIdx = 0; bIdx < bSize; bIdx++) {
            ans = max(ans, solve(aIdx, bIdx));
        }
    }

    cout << ans;
}