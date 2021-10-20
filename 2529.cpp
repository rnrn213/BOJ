#include <bits/stdc++.h>

using namespace std;

int k;
vector<char> inequalitysigns;
string minValue = "", maxValue = "";

void solve(string n, vector<bool>& isUsed) {
    if (n.size() == k + 1) {
        if (n < minValue)
            minValue = n;
        if (n > maxValue)
            maxValue = n;
        return;
    }

    int idx = n.size() - 1;
    for (int i = 0; i <= 9; i++) {
        if (!isUsed[i]) {
            if (inequalitysigns[idx] == '>') {
                if (static_cast<int>(n[idx] - '0') > i) {
                    isUsed[i] = true;
                    solve(n + to_string(i), isUsed);
                    isUsed[i] = false;
                }
            }
            if (inequalitysigns[idx] == '<') {
                if (static_cast<int>(n[idx] - '0') < i) {
                    isUsed[i] = true;
                    solve(n + to_string(i), isUsed);
                    isUsed[i] = false;
                }
            }
        }
    }
}

int main() {
    cin >> k;
    inequalitysigns = vector<char>(k);
    for (int i = 0; i < k; i++) {
        cin >> inequalitysigns[i];
        minValue += "9";
        maxValue += "0";
    }

    for (int i = 0; i <= 9; i++) {
        vector<bool> isUsed(10, false);
        isUsed[i] = true;
        solve(to_string(i), isUsed);
    }

    cout << maxValue << "\n" << minValue;
}