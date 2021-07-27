#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> realMelody(n);
    for (int i = 0; i < n; i++) {
        cin >> realMelody[i];
    }
    cin >> m;
    vector<int> dreamMelody(m);
    for (int i = 0; i < m; i++) {
        cin >> dreamMelody[i];
    }

    int minDepth = 100000, maxDepth = -1;
    for (int i = 0; i < m; i++) {
        if (dreamMelody[i] == realMelody[0]) {
            int interval = 1;
            while (i + (n - 1) * interval <= m) {
                bool isValid = true;
                for (int j = 1; j < n; j++) {
                    if (dreamMelody[i + interval * j] != realMelody[j]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    minDepth = min(minDepth, interval - 1);
                    maxDepth = max(maxDepth, interval - 1);
                }
                interval++;
            }
        }
    }
    if (minDepth == 100000 && maxDepth == -1) cout << -1;
    else cout << minDepth << " " << maxDepth;
}