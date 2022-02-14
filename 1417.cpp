#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> votes(N);
    for (int i = 0; i < N; i++) {
        cin >> votes[i];
    }

    int cnt = 0;
    if (N > 1) {        
        sort(votes.begin() + 1, votes.end(), greater<>());
        
        while (votes[0] <= votes[1]) {
            votes[1]--;
            votes[0]++;
            cnt++;

            sort(votes.begin() + 1, votes.end(), greater<>());
        }
    }

    cout << cnt;
}