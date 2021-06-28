#include <bits/stdc++.h>

using namespace std;

bool isValidTime(int h, int x1, int x2) {
    return (h >= 1 && h <= 12) && (x1 >= 0 && x1 < 60) && (x2 >= 0 && x2 < 60);
}

int main() {
    int a, b, c;
    char d;
    cin >> a >> d >> b >> d >> c;

    int count = 0;
    if (isValidTime(a, b, c))
        count++;
    if (isValidTime(a, c, b))
        count++;
    if (isValidTime(b, a, c))
        count++;
    if (isValidTime(b, c, a))
        count++;
    if (isValidTime(c, a, b))
        count++;
    if (isValidTime(c, b, a))
        count++;
    
    cout << count;
}