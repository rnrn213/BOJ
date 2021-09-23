#include <bits/stdc++.h>

using namespace std;

vector<int> getPrimeNumbers(int K) {
    vector<int> primeNumbers;

    for (int i = 2; i <= K; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                cnt++;
        }

        if (cnt == 2)
            primeNumbers.push_back(i);
    }

    return primeNumbers;
}

vector<int> solve(int K, const vector<int>& primeNumbers) {
    vector<int> ret;

    for (int i = 0; i < primeNumbers.size(); i++) {
        for (int j = 0; j < primeNumbers.size(); j++) {
            for (int k = 0; k < primeNumbers.size(); k++) {
                if (K == primeNumbers[i] + primeNumbers[j] + primeNumbers[k])
                    return ret = {primeNumbers[i], primeNumbers[j], primeNumbers[k]};
            }
        }
    }

    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int K;
        cin >> K;
        vector<int> primeNumbers = getPrimeNumbers(K);
        vector<int> ans = solve(K, primeNumbers);
        if (ans.size() == 0)
            cout << 0;
        else {
            sort(ans.begin(), ans.end());
            for (auto n: ans)
                cout << n << " ";
        }
        cout << "\n";
    }
}