#include <bits/stdc++.h>

using namespace std;

string S;

int getSum(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += S[i] - '0';
    }
    return sum;
}

int main() {
    cin >> S;

    int start = 0, end = 1, maxLen = 0;
    while (start != S.size() - 1) {
        int mid = (start + end) / 2;
        int frontHalfSum = getSum(start, mid);
        int backHalfSum = getSum(mid + 1, end);

        if (frontHalfSum == backHalfSum && end - start + 1 > maxLen) {
            maxLen = end - start + 1;
        }

        end += 2;
        if (end >= S.size()) {
            start++;
            end = start + 1;
        }
    }
    cout << maxLen;
}