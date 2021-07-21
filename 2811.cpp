#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> feelings(N + 1), flower(N + 1, 0), longestDepressionTermIdx;
    int i = 1, longestDepressionTerm = 0;
    while (i <= N) {
        cin >> feelings[i];
        if (feelings[i] < 0) {
            int cnt = 0, idx = i;
            while (feelings[i] < 0 && i < N) {
                cnt++;
                i++;
                cin >> feelings[i];
            }
            if (feelings[i] < 0 && i == N) {
                cnt++;
            }
            if (cnt > longestDepressionTerm) {
                longestDepressionTerm = cnt;
                longestDepressionTermIdx.clear();
                longestDepressionTermIdx.push_back(idx);
            }
            if (cnt == longestDepressionTerm) {
                longestDepressionTermIdx.push_back(idx);
            }

            int start = (idx - 2 * cnt >= 1) ? idx - 2 * cnt : 1;
            int end = idx - 1;
            for (int j = start; j <= end; j++) {
                flower[j] = 1;
            }
        }
        i++;
    }

    int ans = 0;
    for (int i = 0; i < longestDepressionTermIdx.size(); i++) {
        vector<int> tempFlower = flower;

        int start = (longestDepressionTermIdx[i] - 3 * longestDepressionTerm >= 1) ? longestDepressionTermIdx[i] - 3 * longestDepressionTerm : 1;
        int end = longestDepressionTermIdx[i] - 1;
        for (int j = start; j <= end; j++) {
            tempFlower[j] = 1;
        }

        int Flowers = 0;
        for (int j = 1; j <= N; j++) {
            if (tempFlower[j] == 1) Flowers++;
        }
        ans = max(ans, Flowers);
    }
    cout << ans;
}