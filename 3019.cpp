#include <bits/stdc++.h>

using namespace std;

vector< vector< vector< vector<int> > > > blocks = { { {{0, 0}} }, { {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}} }, { {{0, 0}, {0, 1}, {1, 0}, {1, 1}} }, { {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {1, -1}, {2, -1}} }, { {{0, 0}, {0, -1}, {1, -1}, {1, -2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}} }, { {{0, 0}, {0, 1}, {1, 1}, {0, 2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}, {{0, 0}, {1, 0}, {1, -1}, {2, 0}}, {{0, 0}, {1, 0}, {1, -1}, {1, 1}} }, { {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {2, 0}, {2, -1}} }, { {{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {1, 0}, {1, -1}, {1, -2}}, {{0, 0}, {1, 0}, {2, 0}, {2, 1}} } };

int C, P;
vector< vector<int> > tetrisMap;
vector<int> heights;

bool isValid() {
    for (int i = 0; i < C; i++) {
        int prev = tetrisMap[heights[i]][i];
        for (int j = heights[i] + 1; j < 150; j++) {
            if (prev == 0 && tetrisMap[j][i] == 1)
                return false;
            prev = tetrisMap[j][i];
        }
    }

    return true;
}

int main() {
    cin >> C >> P;
    tetrisMap = vector< vector<int> >(150, vector<int>(C, 0));
    heights = vector<int>(C);
    for (int i = 0; i < C; i++) {
        cin >> heights[i];
        for (int j = 0; j < heights[i]; j++) {
            tetrisMap[j][i] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < blocks[P].size(); i++) {
        for (int j = 0; j < C; j++) {
            bool canPutBlock = true;
            for (int k = 0; k < 4; k++) {
                if (heights[j] + blocks[P][i][k][0] < 0 || j + blocks[P][i][k][1] < 0 || j + blocks[P][i][k][1] >= C) {
                    canPutBlock = false;
                    break;
                }
                if (tetrisMap[heights[j] + blocks[P][i][k][0]][j + blocks[P][i][k][1]] == 1) {
                    canPutBlock = false;
                    break;
                }
            }

            if (canPutBlock) {
                for (int k = 0; k < 4; k++) {
                    tetrisMap[heights[j] + blocks[P][i][k][0]][j + blocks[P][i][k][1]] = 1;
                }
                if (isValid())
                    cnt++;
                for (int k = 0; k < 4; k++) {
                    tetrisMap[heights[j] + blocks[P][i][k][0]][j + blocks[P][i][k][1]] = 0;
                }
            }
        }
    }

    cout << cnt;
}