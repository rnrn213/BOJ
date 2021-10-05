#include <bits/stdc++.h>

using namespace std;

int N, M, B;
vector< vector<int> > housingSite;

int main() {
    cin >> N >> M >> B;
    housingSite = vector< vector<int> >(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> housingSite[i][j];
        }
    }

    int minTime = 1000000000, blocksHeightWhenMinTime;
    for (int h = 256; h >= 0; h--) {
        int totalBlocks = B, usingBlocks = 0, usingTime = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (housingSite[i][j] == h)
                    continue;
                else if (housingSite[i][j] > h) {
                    totalBlocks += housingSite[i][j] - h;
                    usingTime += 2 * (housingSite[i][j] - h);
                }
                else {
                    usingBlocks += h - housingSite[i][j];
                    usingTime += h - housingSite[i][j];
                }
            }
        }

        if (totalBlocks < usingBlocks)
            continue;
        
        if (usingTime < minTime) {
            minTime = usingTime;
            blocksHeightWhenMinTime = h;
        }
    }

    cout << minTime << " " << blocksHeightWhenMinTime;
}