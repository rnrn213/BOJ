#include <bits/stdc++.h>

using namespace std;

int ASize, BSize, cache[1000][1000], choice[1000][1000][2];
string A, B;

int solve(int aIdx, int bIdx) {
    if (aIdx == ASize || bIdx == BSize) return 0;

    int& ret = cache[aIdx][bIdx];
    if (ret != -1) return ret;
    ret = 0;

    int choiceAIdx = -1, choiceBIdx = -1;
    if (A[aIdx] == B[bIdx]) {
        ret = 1 + solve(aIdx + 1, bIdx + 1);
        choiceAIdx = aIdx + 1;
        choiceBIdx = bIdx + 1;
    }

    int cand = solve(aIdx + 1, bIdx);
    if (ret < cand) {
        ret = cand;
        choiceAIdx = aIdx + 1;
        choiceBIdx = bIdx;
    }

    cand = solve(aIdx, bIdx + 1);
    if (ret < cand) {
        ret = cand;
        choiceAIdx = aIdx;
        choiceBIdx = bIdx + 1;
    }

    choice[aIdx][bIdx][0] = choiceAIdx;
    choice[aIdx][bIdx][1] = choiceBIdx;

    
    return ret;
}

string reconstruct(int aIdx, int bIdx) {
    if (aIdx == ASize || bIdx == BSize) return "";
    string ret = "";
    if (A[aIdx] == B[bIdx]) 
        ret += A[aIdx];

    int nextAIdx = choice[aIdx][bIdx][0],
        nextBIdx = choice[aIdx][bIdx][1];
    if (nextAIdx == -1) return "";
    return ret + reconstruct(nextAIdx, nextBIdx);
}

int main() {
    memset(cache, -1, sizeof(cache));

    cin >> A >> B;
    ASize = A.size();
    BSize = B.size();

    cout << solve(0, 0) << "\n" << reconstruct(0, 0);
}