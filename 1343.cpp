#include <bits/stdc++.h>

using namespace std;

int main() {
    string B, ans = "";
    cin >> B;

    int i = 0;
    while (i < B.size()) {
        if (B[i] == 'X') {
            int j = i;
            while (j < B.size() && B[j] == 'X')
                j++;
            
            while (i < j) {
                if (j - i >= 4) {
                    ans += "AAAA";
                    i += 4;
                }
                else if (j - i >= 2) {
                    ans += "BB";
                    i += 2;
                }
                else {
                    cout << -1;
                    return 0;
                }
            }
        }
        else {
            ans += ".";
            i++;
        }
    }

    cout << ans;
}