#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        int count = 0, prev = B[0];
        for (int j = 0; j < N; j++) {
            if (B[j] == B[i]) continue;

            if (B[j] == prev) count++;
            else {
                prev = B[j];
                if (count > maxLength) maxLength = count;
                count = 1;
            }
        }
        if (count > maxLength) maxLength = count;
    }
    cout << maxLength;
}