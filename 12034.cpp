#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> P(N * 2);
        for (int j = 0; j < N * 2; j++) {
            cin >> P[j];
        }

        queue<int> q;
        vector<int> ans;
        for (int j = 0; j < N * 2; j++) {
            if (q.empty()) {
                if (P[j] <= 750000000)
                    q.push((P[j] / 3) * 4);
                ans.push_back(P[j]);
            }
            else {
                if (P[j] == q.front()) {
                    q.pop();
                }
                else {
                    if (P[j] <= 750000000)
                        q.push((P[j] / 3) * 4);
                    ans.push_back(P[j]);
                }
            }
        }

        cout << "Case #" << i + 1 << ": ";
        for (auto price: ans) {
            cout << price << " ";
        }
        cout << "\n";
    }
}