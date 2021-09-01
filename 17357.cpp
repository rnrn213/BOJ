#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int getSum(int start, int k) {
    int sum = 0;
    for (int i = start; i < start + k; i++) {
        sum += arr[i];
    }

    return sum;
}

double getStandardDeviation(int start, int k) {
    double average = static_cast<double>(getSum(start, k)) / k;

    double variance = 0.0;
    for (int i = start; i < start + k; i++) {
        variance += pow(arr[i] - average, 2);
    }
    variance /= k;

    return sqrt(variance);
}

int main() {
    cin >> N;
    arr = vector<int>(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int k = 1; k <= N; k++) {
        double maxStandardDeviation = -1.0;
        int ans;

        for (int i = 1; i <= N - k + 1; i++) {
            double standardDeviation = getStandardDeviation(i, k);
            if (standardDeviation - maxStandardDeviation > numeric_limits<double>::epsilon()) {
                maxStandardDeviation = standardDeviation;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}