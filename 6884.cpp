#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(100000001, true);

void initIsPrime() {
    for (int i = 2; i <= 10000; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= 100000000; j += i)
                isPrime[j] = false;
    }
}

string solve(vector<int>& arr, vector<int>& prefixSum) {
    int n = arr.size() - 1;
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int sum = prefixSum[i + length - 1] - prefixSum[i - 1];
            if (isPrime[sum]) {
                string ret = "Shortest primed subsequence is length " + to_string(length) + ": ";
                for (int j = i; j < i + length; j++) {
                    ret += to_string(arr[j]) + " ";
                }
                return ret + "\n";
            }
        }
    }

    return "This sequence is anti-primed.\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    initIsPrime();

    int t;
    cin >> t;
    while (t) {
        int n;
        cin >> n;
        vector<int> arr(n + 1), prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            prefixSum[i] = arr[i] + prefixSum[i - 1];
        }

        cout << solve(arr, prefixSum);

        t--;
    }
}