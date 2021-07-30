#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, cnt = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (char c: s) {
            if (c - '0' == d) cnt++;
        }
    }
    cout << cnt;
}