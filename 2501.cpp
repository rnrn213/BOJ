#include <bits/stdc++.h>

using namespace std;



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> divisors;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) divisors.push_back(i);
    }

    if (K > divisors.size()) cout << 0;
    else cout << divisors[K - 1];
}