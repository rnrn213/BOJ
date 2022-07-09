#include <bits/stdc++.h>

using namespace std;

long long getMultiplication(long long A, long long B, long long C) {
    if (B == 1)
        return A;
    
    long long temp = getMultiplication(A, B / 2, C);
    if (B % 2 == 1)
        return (((temp * temp) % C) * A) % C;
    else
        return (temp * temp) % C;
}


int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << getMultiplication(A, B, C) % C;
}