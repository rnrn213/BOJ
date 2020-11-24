#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum;
}