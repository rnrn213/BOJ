#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) break;

        vector<int> num(N);
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }

        sort(num.begin(), num.end(), greater<>());

        if (num[N - 1] == 0) {
            int i = N - 2;
            while (num[i] == 0) {
                i--;
            }

            num[N - 1] = num[i];
            num[i] = 0;
        }
        if (num[N - 2] == 0) {
            int i = N - 3;
            while (num[i] == 0) {
                i--;
            }

            num[N - 2] = num[i];
            num[i] = 0;
        }

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += num[i] * pow(10, i / 2);
        }

        cout << sum << "\n";
    }
    
}