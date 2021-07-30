#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int maxFriends = (a > b) ? b : a;
    for (int i = 1; i <= maxFriends; i++) {
        if (a % i == 0 && b % i == 0) {
            cout << i << " " << a / i << " " << b / i << "\n";
        }
    }
}