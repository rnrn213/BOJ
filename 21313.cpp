#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector< vector<bool> > O(N + 1, vector<bool>(9, false));
    vector<int> ans;

    O[1][1] = O[2][1] = true;
    ans.push_back(1);
    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= 8; j++) {
            if (O[i][j] == false) {
                O[i][j] = O[i + 1][j] = true;
                ans.push_back(j);
                break;
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (O[N][i] == false && O[1][i] == false) {
            O[N][i] = O[1][i] = true;
            ans.push_back(i);
            break;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}