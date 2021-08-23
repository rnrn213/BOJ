#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        vector< pair< vector<int>, int > > prize(n);
        for (int j = 0; j < n; j++) {
            int stickersSize, prizeMoney;
            cin >> stickersSize;
            vector<int> stickers(stickersSize);
            for (int k = 0; k < stickersSize; k++) {
                cin >> stickers[k];
            }
            cin >> prizeMoney;
            prize[j] = make_pair(stickers, prizeMoney);
        }
        vector<int> sticker(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            cin >> sticker[j];
        }

        int maxPrize = 0;
        for (int j = 0; j < n; j++) {
            int minSticker = 101;
            for (int k = 0; k < prize[j].first.size(); k++) {
                if (sticker[prize[j].first[k]] < minSticker)
                    minSticker = sticker[prize[j].first[k]];
            }
            maxPrize += minSticker * prize[j].second;
        }
        cout << maxPrize << "\n";
    }
}