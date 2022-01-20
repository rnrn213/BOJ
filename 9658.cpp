#include <bits/stdc++.h>

using namespace std;

const int SK = 1, CY = 0;

int cache[1001][2];


int main() {
    int N;
    cin >> N;

    cache[0][0] = cache[0][1] = 1;
    cache[1][0] = cache[1][1] = 0;
    cache[2][0] = cache[2][1] = 1;
    cache[3][0] = cache[3][1] = 0;
    for (int i = 4; i <= N; i++) {
        cache[i][0] = !cache[i - 1][1] || !cache[i - 3][1] || !cache[i - 4][1];
        cache[i][1] = !cache[i - 1][0] || !cache[i - 3][0] || !cache[i - 4][0];
    }

    if (cache[N][SK])
        cout << "SK";
    else
        cout << "CY";
}