#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for (int B = 1; B <= N; B++) {
        for (int C = B + 2; C <= N - B; C++) {
            if (N - (B + C) > 0 && (N - (B + C)) % 2 == 0)
                cnt++;
        }
    }

    cout << cnt;
}