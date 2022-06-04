#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> woods(N);
    for (int i = 0; i < N; i++) {
        cin >> woods[i];
    }

    sort(woods.begin(), woods.end(), greater<int>());

    int cnt = 0, H = woods[0], totalCutLength = 0;
    for (int i = 0; i < N; i++) {
        if (totalCutLength >= M) 
            break;
        
        while (H > woods[i]) {
            H--;
            totalCutLength += cnt;

            if (totalCutLength >= M)
                break;
        }

        cnt++;
    }

    if (totalCutLength < M) {
        while (H > 0) {
            H--;
            totalCutLength += cnt;

            if (totalCutLength >= M)
                break;
        }
    }

    cout << H;
}