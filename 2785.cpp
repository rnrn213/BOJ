#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> chains(N);
    for (int i = 0; i < N; i++) {
        cin >> chains[i];
    }

    sort(chains.begin(), chains.end());

    int i = 0, ans = 0;
    while (N > 1) {
        chains[i]--;
        ans++;
        N--;

        if (chains[i] == 0) {
            N--;
            i++;
        }
    }

    cout << ans;
}