#include <bits/stdc++.h>

using namespace std;

int D, K;
vector< pair<int, int> > v = {make_pair(0, 0), make_pair(1, 0), make_pair(0, 1)};

int main() {
    cin >> D >> K;

    for (int i = 3; i <= D; i++) {
        v.push_back(make_pair(v[i - 2].first + v[i - 1].first, v[i - 2].second + v[i - 1].second));
    }

    int A = 1, B;
    while (true) {
        if ((K - v[D].first * A) % v[D].second == 0) {
            B = (K - v[D].first * A) / v[D].second;
            break;
        }

        A++;
    }

    cout << A << "\n" << B;
}