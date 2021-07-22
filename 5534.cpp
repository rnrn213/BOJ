#include <bits/stdc++.h>

using namespace std;

bool isValidSignboard(const string& name, const string& oldSignboard) {
    for (int i = 0; i < oldSignboard.size(); i++) {
        if (name[0] == oldSignboard[i]) {
            for (int j = i + 1; j < oldSignboard.size(); j++) {
                if (name[1] == oldSignboard[j]) {
                    bool isValid = true;
                    int gap = j - i, nameIdx = 2, k;
                    for (k = j + gap; k < oldSignboard.size() && nameIdx < name.size(); k += gap) {
                        if (name[nameIdx] != oldSignboard[k]) {
                            isValid = false;
                            break;
                        }
                        nameIdx++;
                    }
                    if (isValid && nameIdx == name.size()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    string name, oldSignboard;
    cin >> name;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> oldSignboard;

        if (isValidSignboard(name, oldSignboard)) cnt++;
    }
    cout << cnt;
}