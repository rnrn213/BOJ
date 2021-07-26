#include <bits/stdc++.h>

using namespace std;

bool isValid(int num) {
    vector<bool> isExist(10, false);
    string s = to_string(num);
    for (int i = 0; i < s.size(); i++) {
        if (isExist[s[i] - '0']) return false;
        isExist[s[i] - '0'] = true;
    }
    return true;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        int cnt = 0;
        for (int num = N; num <= M; num++) {
            if (isValid(num)) cnt++;
        }
        cout << cnt << "\n";
    }
}