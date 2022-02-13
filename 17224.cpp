#include <bits/stdc++.h>

using namespace std;

int N, L, K;

int main() {
    cin >> N >> L >> K;
    vector< pair<int, int> > sub(N);
    for (int i = 0; i < N; i++) {
        cin >> sub[i].second >> sub[i].first;
    }
    sort(sub.begin(), sub.end());

    int solve = 0, score = 0;
    for (int i = 0; i < N; i++) {
        if (solve == K)
            break;
        if (sub[i].first <= L) {
            solve++;
            score += 140;
        }
        else if (sub[i].second <= L) {
            solve++;
            score += 100;
        }
    }

    cout << score;
}