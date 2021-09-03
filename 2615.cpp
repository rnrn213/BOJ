#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > goBoard(19, vector<int>(19));
pair<int, int> ans;

void input() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> goBoard[i][j];
        }
    }
}
// i, j 뒤에 바둑알 색깔 체크해야함
bool isOmok(int i, int j) {
    bool ret = true;

    if (j < 15) {
        int n = 0;
        for (; n < 5; n++) {
            if (goBoard[i][j + n] != goBoard[i][j]) {
                ret = false;
                break;
            }
        }
        if ((j + n != 19 && goBoard[i][j + n] == goBoard[i][j]) || 
                (j > 0 && goBoard[i][j - 1] == goBoard[i][j]))
            ret = false;

        if (ret == true)
            return true;

        if (i > 3) {
            ret = true;
            n = 0;
            for (; n < 5; n++) {
                if (goBoard[i - n][j + n] != goBoard[i][j]) {
                    ret = false;
                    break;
                }
            }
            if ((i - n >= 0 && goBoard[i - n][j + n] == goBoard[i][j]) || 
                    (i < 18 && j > 0 && goBoard[i + 1][j - 1] == goBoard[i][j]))
                ret = false;
            
            if (ret == true)
                return true;
        }

        if (i < 15) {
            ret = true;
            n = 0;
            for (; n < 5; n++) {
                if (goBoard[i + n][j + n] != goBoard[i][j]) {
                    ret = false;
                    break;
                }
            }
            if ((i + n != 19 && j + n != 19 && goBoard[i + n][j + n] == goBoard[i][j]) || 
                    (i > 0 && j > 0 && goBoard[i - 1][j - 1] == goBoard[i][j]))
                ret = false;

            if (ret == true)
                return true;
        }
    }

    if (i < 15) {
        ret = true;
        int n = 0;
        for (; n < 5; n++) {
            if (goBoard[i + n][j] != goBoard[i][j]) {
                ret = false;
                break;
            }
        }
        if ((i + n != 19 && goBoard[i + n][j] == goBoard[i][j]) || 
                (i > 0 && goBoard[i - 1][j] == goBoard[i][j]))
            ret = false;
        
        if (ret == true)
            return true;
    }

    return false;
}

int solve() {
    int ret = 0;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (goBoard[i][j] != 0 && isOmok(i, j)) {
                ret = goBoard[i][j];
                ans.first = i + 1, ans.second = j + 1;
            }
        }
    }

    return ret;
}

int main() {
    input();
    int ret = solve();
    cout << ret;
    if (ret != 0)
        cout << "\n" << ans.first << " " << ans.second;
}