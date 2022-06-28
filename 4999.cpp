#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string ans = (A.size() >= B.size()) ? "go" : "no";
    cout << ans;
}