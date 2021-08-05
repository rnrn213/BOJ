#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "0";
    for (int i = 1; i < 1000; i++) {
        s += to_string(i);
    }

    string hwan;
    cin >> hwan;
    int numSize = 1, start = 1, end;
    for (int i = 1; i <= s.size() - hwan.size(); i += numSize) {
        if (start / 10) numSize = 2;
        if (start / 100) numSize = 3;
        
        bool isValid = true;
        int tempNumSize = numSize;
        end = 0;
        for (int j = 0; j < hwan.size(); j += tempNumSize) {
            if (end / 9) tempNumSize = 2;
            if (end / 99) tempNumSize = 3;
            for (int k = 0; k < tempNumSize; k++) {
                if (s[i + j + k] != hwan[j + k]) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) break;
            end = stoi(hwan.substr(j, tempNumSize));
        }

        if (isValid) {
            cout << start << " " << end;
            break;
        }

        start++;
    }
}