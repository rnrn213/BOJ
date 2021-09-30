#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> shareCards(N), teamCards(N);
    for (int i = 0; i < N; i++) {
        cin >> shareCards[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> teamCards[i];
    }
    sort(shareCards.begin(), shareCards.end());
    sort(teamCards.begin(), teamCards.end());

    for (int i = 0; i < K; i++) {
        int left = shareCards[0], right = shareCards[shareCards.size() - 1];

        int max = -100000001, idx = -1;
        for (int j = 0; j < teamCards.size(); j++) {
            if (left * teamCards[j] > max) {
                max = left * teamCards[j];
                idx = j;
            }
            if (right * teamCards[j] > max) {
                max = right * teamCards[j];
                idx = j;
            }
        }
        teamCards.erase(teamCards.begin() + idx);
    }

    int left = shareCards[0], right = shareCards[shareCards.size() - 1], ans = -100000001;
    for (int i = 0; i < teamCards.size(); i++) {
        if (left * teamCards[i] > ans)
            ans = left * teamCards[i];
        if (right * teamCards[i] > ans)
            ans = right * teamCards[i];
    }

    cout << ans;
}