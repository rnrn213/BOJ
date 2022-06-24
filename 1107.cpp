#include <bits/stdc++.h>

using namespace std;

bool isValid(int N, const vector<bool>& isBroken) {
    if (N == 0) {
        if (isBroken[0])
            return false;
        else
            return true;
    }

    while (N) {
        if (isBroken[N % 10])
            return false;
        N /= 10;
    }

    return true;
}

bool isExistHigh(const vector<bool>& isBroken) {
    for (int i = 1; i <= 9; i++) {
        if (!isBroken[i])
            return true;
    }

    return false;
}

int getBtnCnt(int N, const vector<bool>& isBroken) {
    int ret = 1000000000;

    int low = N, btnCnt = 0;
    while (low >= 0) {
        if (isValid(low, isBroken))
            break;
        
        low--;
        btnCnt++;
    }
    if (low >= 0) {
        if (low == 0)
            btnCnt++;
        else {
            while (low) {
                low /= 10;
                btnCnt++;
            }
        }

        ret = min(ret, btnCnt);
    }

    btnCnt = 0;
    if (isExistHigh(isBroken)) {
        int high = N;
        while (true) {
            if (isValid(high, isBroken))
                break;
            
            high++;
            btnCnt++;
        }

        if (high == 0)
            btnCnt = 1;

        while (high) {
            high /= 10;
            btnCnt++;
        }

        ret = min(ret, btnCnt);
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> isBroken(10, false);
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        isBroken[b] = true;
    }

    if (M == 10) {
        cout << abs(N - 100);
    }
    else {
        cout << min(abs(N - 100), getBtnCnt(N, isBroken));
    }
}