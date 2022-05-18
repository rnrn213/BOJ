#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> cnt(10001, 0);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        cnt[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        if (cnt[i] == 0)
            continue;
        
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << "\n";
        }
    }
}