#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int main() {
    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1;
    for (int h = 1; h <= 10; h++) {
        int maxLength = 1, length = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > h + 2 || A[i] < h) {
                if (length > maxLength) {
                    maxLength = length;
                }
                length = 0;
            }

            if (A[i] >= h && A[i] <= h + 2) {
                length++;
            }
        }
        if (length > maxLength) {
            maxLength = length;
        }
        if (maxLength > ans) {
            ans = maxLength;
        }
    }

    cout << ans;
}