#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int K = 1;
    for (; K <= 100; K++) {
        if (1 + K + K * K == N)
            break;
    }

    cout << K;
}