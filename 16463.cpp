#include <bits/stdc++.h>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int N;
    cin >> N;
    int day = 2, cnt = 0;
    for (int i = 2019; i <= N; i++) {
        for (int j = 0; j < 12; j++) {
            if (day == 0) cnt++;

            if ((i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)) && j == 1) {
                day += 1;
            }
            day = (day + days[j]) % 7;
        }
    }

    cout << cnt;
}