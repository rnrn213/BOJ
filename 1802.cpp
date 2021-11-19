#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int solve(int L, int R) {
    if (L == R)
        return s[L];
    
    int left = solve(L, (L + R) / 2 - 1);
    int right = solve((L + R) / 2 + 1, R);
    if (left == -1 || right == -1 || left == right)
        return -1;
    else
        return s[(L + R) / 2];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T) {
        cin >> s;

        if (solve(0, s.size() - 1) == -1)
            cout << "NO\n";
        else
            cout << "YES\n";

        T--;
    }
}