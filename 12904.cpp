#include <bits/stdc++.h>

using namespace std;

string S, T;

int main() {
    cin >> S >> T;

    while (S.size() < T.size()) {
        if (*(T.end() - 1) == 'A') {
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if (S == T) cout << 1;
    else cout << 0;

    return 0;
}