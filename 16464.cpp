#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        string ans = "GoHanGang\n";
        for (int j = 2; ((j - 1) * j) / 2 <= K; j++) {
            if ((K - ((j - 1) * j) / 2) % j == 0) {
                ans = "Gazua\n";
                break;
            }
        }

        cout << ans;
    }
}