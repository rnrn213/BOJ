#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        if (K % 2 == 1) {
            cout << "Gazua\n";
            continue;
        }
        else {
            string ans = "Gazua\n";

            for (int a = 2; a <= K; a += a)  {
                if (a == K)
                    ans = "GoHanGang\n";
            }

            cout << ans;
        }
    }
}