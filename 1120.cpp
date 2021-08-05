#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int minDiff = 51;
    for (int i = 0; i <= B.size() - A.size(); i++) {
        int diff = 0;
        for (int j = 0; j < A.size(); j++) {
            if (B[i + j] != A[j]) diff++;
        }
        if (diff < minDiff) minDiff = diff;
    }

    cout << minDiff;
}