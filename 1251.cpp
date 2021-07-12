#include <bits/stdc++.h>

using namespace std;

string getReverse(string s) {
    string ret;
    for (int i = s.size() - 1; i >= 0; i--) {
        ret += s[i];
    }
    return ret;
}

int main() {
    string s;
    vector<string> reverse;
    cin >> s;

    for (int i = 1; i <= s.size() - 2; i++) {
        for (int j = 1; j <= s.size() - i - 1; j++) {
            reverse.push_back(getReverse(s.substr(0, i)) + getReverse(s.substr(i, j)) + getReverse(s.substr(i + j, string::npos)));
        }
    }
    sort(reverse.begin(), reverse.end());
    cout << reverse[0];
}