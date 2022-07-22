#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> saleNumber;

int getGCD(int y, int x) {
    if (x == 0)
        return y;
    else 
        return getGCD(x, y % x);
}

int getGCDArray(int start, int end) {
    if (end - start == 1)
        return saleNumber[start];
    else if (end - start == 2)
        return getGCD(saleNumber[start], saleNumber[start + 1]);
    else {
        return getGCD(saleNumber[start], getGCDArray(start + 1, end));
    }
}


int solve(int start, int end) {
    if (start + 1 == end) {
        return saleNumber[start];
    }

    int mid = (start + end) / 2;

    return max(getGCDArray(start, mid) + solve(mid, end), solve(start, mid) + getGCDArray(mid, end));
}

int main() {
    cin >> N;
    saleNumber = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> saleNumber[i];
    }

    cout << solve(0, N);
}