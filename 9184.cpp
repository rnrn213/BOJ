#include <bits/stdc++.h>

using namespace std;

int a, b, c, cache[21][21][21];

void initCache() {
    memset(cache, -1, sizeof(cache));
}

bool input() {
    cin >> a >> b >> c;
    return !(a == -1 && b == -1 && c == -1);
}

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    int& ret = cache[a][b][c];
    if (ret != -1) return ret;
    if (a < b && b < c) return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    while (input()) {
        initCache();
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n'; 
    }
}