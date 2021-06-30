#include <bits/stdc++.h>

using namespace std;

bool isAllAppear(const vector<bool>& appear) {
    for (int i = 0; i < appear.size(); i++) {
        if (!appear[i]) return false;
    }
    return true;
}

void checkAppear(long long n, vector<bool>& appear) {
    while (n) {
        appear[n % 10] = true;
        n /= 10;
    }
}

int main() {
    long long n;
    while (cin >> n) {
        vector<bool> appear(10, false);

        long long initialN = n, k = 1;
        while (true) {
            checkAppear(n, appear);
            if (isAllAppear(appear)) break;
            k++;
            n += initialN;
        }
        cout << k << "\n";
    }
}