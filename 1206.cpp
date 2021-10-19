#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> averageScore(N);
    for (int i = 0; i < N; i++) {
        cin >> averageScore[i];
    }

    int people = 1;
    while (true) {
        bool isVaild = true;

        for (int i = 0; i < N; i++) {
            double temp = averageScore[i] * people;

            if ((temp - static_cast<int>(temp)) < 0.0000001)
                continue;
            if (((temp - static_cast<int>(temp)) < 1.0 - 0.0009999999 * people)) {
                isVaild = false;
                break;
            }
        }

        if (isVaild) {
            cout << people;
            break;
        }

        people++;
    }
}