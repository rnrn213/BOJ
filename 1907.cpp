#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector< vector<int> > molecule(3, vector<int>(3));
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '=') {
            j++;
            continue;
        }
        if (s[i] == 'C') {
            if (s[i + 1] >= '2' && s[i + 1] <= '9') {
                molecule[j][0] += s[i + 1] - '0';
                i++;
            }
            else {
                molecule[j][0]++;
            }
        }
        if (s[i] == 'H') {
            if (s[i + 1] >= '2' && s[i + 1] <= '9') {
                molecule[j][1] += s[i + 1] - '0';
                i++;
            }
            else {
                molecule[j][1]++;
            }
        }
        if (s[i] == 'O') {
            if (s[i + 1] >= '2' && s[i + 1] <= '9') {
                molecule[j][2] += s[i + 1] - '0';
                i++;
            }
            else {
                molecule[j][2]++;
            }
        }
    }

    for (int i = 1; i <= 10; i++) {
        bool isValid = true;
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                isValid = true;
                for (int n = 0; n < 3; n++) {
                    if (molecule[0][n] * i + molecule[1][n] * j != molecule[2][n] * k) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    cout << i << " " << j << " " << k;
                    break;
                }
            }
            if (isValid) break;
        }
        if (isValid) break;
    }
}