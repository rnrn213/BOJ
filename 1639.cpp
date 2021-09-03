#include <bits/stdc++.h>

using namespace std;

int solve(const string& S) {
    int maxLength = 0;

    for (int i = 0; i < S.size(); i++) {
        int maxN = (S.size() - i) / 2;
        for (int N = 1; N <= maxN; N++) {
            int leftSum = 0, rightSum = 0, leftIdx = i, rightIdx = i + N;
            while (leftIdx < i + N) {
                leftSum += S[leftIdx] - '0';
                rightSum += S[rightIdx] - '0';

                leftIdx++;
                rightIdx++;
            }

            if (leftSum == rightSum && 2 * N > maxLength) {
                maxLength = 2 * N;
            }
        }
    }

    return maxLength;
}

int main() {
    string S;
    cin >> S;

    cout << solve(S);
}