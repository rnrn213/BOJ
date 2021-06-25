#include <bits/stdc++.h>

using namespace std;



int main() {
    int N;
    cin >> N;

    int A = 1, B = 1, count = 0;
    while (A <= 500 && B <= 500) {
        if (static_cast<int>(pow(A, 2)) - static_cast<int>(pow(B, 2)) == N) {
            count++;
            A++;
            B++;
        }
        else if (static_cast<int>(pow(A, 2)) - static_cast<int>(pow(B, 2)) < N) {
            A++;
        }
        else {
            B++;
        }
    }
    cout << count;
}