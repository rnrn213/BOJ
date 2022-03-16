#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int sSize = s.size(), tSize = t.size();
        bool isSubString = false;
        for (int i = tSize - 1; i >= 0; i--) {
            if (t[i] == s[sSize-1]) {
                int j = sSize - 2;
                while (i >= 0 && j >= 0) {
                    if (t[i] == s[j]) {
                        j--;
                    }
                    i--;
                }

                if (j < 0)
                    isSubString = true;

                break;
            }
        }

        if (isSubString)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}