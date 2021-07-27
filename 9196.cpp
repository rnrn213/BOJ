#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int h, w, diagonal;
        cin >> h >> w;
        if (h == 0 && w == 0) break;

        diagonal = pow(h, 2) + pow(w, 2);
        pair<int, int> ans = make_pair(151, 151);
        int ansDiagonal = pow(ans.first, 2) + pow(ans.second, 2);
        for (int i = 1; i <= 150; i++) {
            for (int j = i + 1; j <= 150; j++) {
                int d = pow(i, 2) + pow(j, 2);
                if (diagonal == d && h < i) {
                    if (d == ansDiagonal && i < ans.first) {
                        ans = make_pair(i, j);
                        ansDiagonal = d;
                    }
                    else if (d < ansDiagonal) {
                        ans = make_pair(i, j);
                        ansDiagonal = d;
                    }
                }
                else if (diagonal < d) {
                    if (d == ansDiagonal && i < ans.first) {
                        ans = make_pair(i, j);
                        ansDiagonal = d;
                    }
                    else if (d < ansDiagonal) {
                        ans = make_pair(i, j);
                        ansDiagonal = d;
                    }
                }
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}