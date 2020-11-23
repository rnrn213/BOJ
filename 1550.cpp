#include <bits/stdc++.h>

using namespace std;

long long hexToDec(string h) {
    long long d = 0;
    long long i = 1;
    for (int j = 0; j < h.size() - 1; j++) {
        i *= 16;
    }
    for (auto c: h) {
        if (c >= '0' && c <= '9') {
            d += static_cast<int>(c - '0') * i;
            //cout << static_cast<int>(c - '0') << '*' << i << '\n';
        }
        else {
            d += static_cast<int>(c - 55) * i;
            //cout << static_cast<int>(c - 55) << '*' << i << '\n';
        }
        i /= 16;
    }
    return d;
}

int main() {
    string h;
    cin >> h;

    cout << hexToDec(h);
}