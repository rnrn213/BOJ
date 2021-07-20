#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > condo(N);
    for (int i = 0; i < N; i++) {
        cin >> condo[i].first >> condo[i].second;
    }
    sort(condo.begin(), condo.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool isValid = true;
        for (int j = i - 1; j >= 0; j--) {
            if (condo[i].second >= condo[j].second) {
                isValid = false;
            }
        }
        if (isValid) cnt++;
    }
    cout << cnt;
}