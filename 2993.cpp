#include <bits/stdc++.h>

using namespace std;

int main() {
    string word;
    cin >> word;

    string ans = "~";
    for (int i = 1; i < word.size() - 1; i++) {
        string tempI = word;
        reverse(tempI.begin(), tempI.begin() + i);
        for (int j = i + 1; j < word.size(); j++) {
            string tempJ = tempI;
            reverse(tempJ.begin() + i, tempJ.begin() + j);
            reverse(tempJ.begin() + j, tempJ.end());
            if (ans > tempJ) ans = tempJ;
        }
    }
    cout << ans;
}