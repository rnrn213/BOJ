#include <bits/stdc++.h>

using namespace std;

int T;
string s;

bool solve(int L, int R) {
    if (L == R)
        return true;
    
    int left = L, right = R;
    while (left < right)
        if (s[left++] == s[right--])
            return false;
    
    return solve(L, right - 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> s;

        if (solve(0, s.size() - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}