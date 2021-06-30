#include <bits/stdc++.h>

using namespace std;

int getArea(int a, int b, int c) {
    return 2 * a * b + 2 * a * c + 2 * b * c;
}

int getCapacity(int a, int b, int c) {
    return a * b * c;
}

int getNextC(int n, int c) {
    for (c = c + 1; c < n; c++) {
        if (n % c == 0) return c;
    }
    return -1;
}

int main() {
    int n, a = 1, b = 1, c = 1;
    cin >> n;

    int minArea = 100000000, minA, minB, minC;
    while (true) {
        for (b = c; b <= n / c; b++) {
            if ((n / c) % b == 0) {
                for (a = c; a <= n / (b * c); a++) {
                    if ((n / (b * c)) % a == 0 && n == getCapacity(a, b, c)) {
                        int area = getArea(a, b, c);
                        if (area < minArea) {
                            minArea = area;
                            minA = a;
                            minB = b;
                            minC = c;
                        }
                    }
                }
            }
        }
        c = getNextC(n, c);
        if (c == -1) break;
    }
    cout << minA << " " << minB << " " << minC;
}