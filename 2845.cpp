#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int L, P;
    cin >> L >> P;

    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        cout << num - L * P << ' ';
    }
}