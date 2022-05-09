#include <bits/stdc++.h>

using namespace std;

int main() {
    int L;
    cin >> L;

    string msg;
    cin >> msg;

    long long ans = 0, r = 1;
    for (int i = 0; i < L; i++) {
        ans = (ans + (msg[i] - 'a' + 1) * r) % 1234567891;
        r = (r * 31) % 1234567891;
    }

    cout << ans;
}