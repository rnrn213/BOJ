#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int t = 0;
    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        t += num;
    }
    cout << t / 60 << '\n' << t % 60;
}