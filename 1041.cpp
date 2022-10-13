#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* dice = new int(6);
    cin >> dice[0] >> dice[1] >> dice[2] >> dice[3] >> dice[4] >> dice[5];

    if (N == 1) {
        int sum = 0, maxValue = -1;
        for (int i = 0; i < 6; i++) {
            sum += dice[i];
            if (dice[i] > maxValue)
                maxValue = dice[i];
        }
        
        cout << sum - maxValue;
    }
    else {
        vector<long long> minNums = {min(dice[0], dice[5]), min(dice[1], dice[4]), min(dice[2], dice[3])};
        sort(minNums.begin(), minNums.end());

        long long sum = 0;
        sum += (minNums[0] + minNums[1] + minNums[2]) * 4;
        sum += (minNums[0] + minNums[1]) * ((N - 1) * 4 + (N - 2) * 4);
        if (N > 2)
            sum += minNums[0] * ((long long)pow(N - 2, 2) + (long long)(N - 1) * (N - 2) * 4);

        cout << sum;
    }


    return 0;
}