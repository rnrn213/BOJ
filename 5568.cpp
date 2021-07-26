#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    vector<string> cards(n), ans;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && k > 2) {
                for (int m = 0; m < n; m++) {
                    if (i != m && j != m && k > 3) {
                        for (int L = 0; L < n; L++) {
                            if (i != L && j != L && m != L) {
                                ans.push_back(cards[i] + cards[j] + cards[m] + cards[L]);
                            }
                        }
                    }
                    else if (i != m && j != m) {
                        ans.push_back(cards[i] + cards[j] + cards[m]);
                    }
                }
            }
            else if (i != j) {
                ans.push_back(cards[i] + cards[j]);
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
}