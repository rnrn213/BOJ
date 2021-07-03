#include <bits/stdc++.h>

using namespace std;

bool isValid(const string& s) {
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) return false;
        }
    }
    return true;
}


int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        int cnt = 1, num = 1;
        string s;
        while (cnt != n) {
            s = to_string(num);
            if (isValid(s)) cnt++;
            num++;
        }
        s = to_string(num);
        while (!isValid(s)) {
            num++;
            s = to_string(num);
        }

        cout << num << "\n";
    }
}