#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T) {
        int N;
        cin >> N;

        bool isPossible = false;
        int b = ceil(sqrt(N)), a = sqrt(pow(b, 2) - N);
        while (pow(b, 2) - pow(a, 2) <= N * 2) {
            if (pow(b, 2) - pow(a, 2) == N) {
                isPossible = true;
                break;
            }

            b++;
            a = sqrt(pow(b, 2) - N);
        }

        if (isPossible)
            cout << a << " " << b << "\n";
        else
            cout << "IMPOSSIBLE\n";
        
        T--;
    }
}