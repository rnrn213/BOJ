#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    int i = 0, Ssize = S.size(), cnt[2] = {0, 0};
    while (i < Ssize) {
        int j = i + 1;
        while (j < Ssize && S[i] == S[j]) {
            j++;
        }
        cnt[S[i] - '0']++;
        i = j;
    }

    cout << min(cnt[0], cnt[1]);
}