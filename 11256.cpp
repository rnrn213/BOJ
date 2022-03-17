#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int j, N;
        cin >> j >> N;
        vector<int> box(N);
        for (int k = 0; k < N; k++) {
            int r, c;
            cin >> r >> c;
            box[k] = r * c;
        }
        sort(box.begin(), box.end(), greater<>());

        int cnt = 0;
        for (int k = 0; k < N; k++) {
            j -= box[k];
            cnt++;
            if (j <= 0)
                break;
        }

        cout << cnt << "\n";
    }
}