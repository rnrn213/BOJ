#include <bits/stdc++.h>

using namespace std;



int main() {
    int a, b, c, d;

    for (a = 5; a <= 100; a++) {
        for (b = 2; b <= a - 3; b++) {
            for (c = b + 1; c <= a - 2; c++) {
                for (d = c + 1; d <= a - 1; d++) {
                    if (static_cast<int>(pow(a, 3)) == static_cast<int>(pow(b, 3)) + 
                        static_cast<int>(pow(c, 3)) + static_cast<int>(pow(d, 3)))
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                }
            }
        }
    }
}