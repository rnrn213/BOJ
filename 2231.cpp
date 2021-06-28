#include<bits/stdc++.h>

using namespace std;

int getDigitSum(int generator) {
    int digitSum = generator;
    while (generator) {
        digitSum += generator % 10;
        generator /= 10;
    }
    return digitSum;
}

int main() {
    int N;
    cin >> N;

    int generator = 1, digitSum = 0;
    while (generator < N) {
        digitSum = getDigitSum(generator);
        if (digitSum == N) break;
        generator++;
    }
    if (generator == N) cout << 0;
    else cout << generator;
}