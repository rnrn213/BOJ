#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    int i = 0, L = S.size(), K = 0;
    while (i < L) {
        int j = i + 1;
        while (j < L && S[i] - 'a' < S[j] - 'a') {
            i = j;
            j++;
        }
        
        i = j;
        K++;
    }

    cout << K;
}