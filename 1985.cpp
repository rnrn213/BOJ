#include <bits/stdc++.h>

using namespace std;

string modifyNum(string num, int idx1, int idx2, int value) {
    num[idx1] += value;
    num[idx2] -= value;

    for (int i = idx1; i > 0; i--) {
        if (num[i] - '0' == -1) {
            num[i] = '9';
            num[i - 1]--;
        }
        if (num[i] - '0' == 10) {
            num[i] = '0';
            num[i - 1]++;
        }
    }
    if (num[0] - '0' == 10) {
        num[0] = '0';
        num = "1" + num;
    }
    return num;
}

string solveModified(string x, string y) {
    for (int i = x.size() - 1; i >= 0; i--) {
        if (y.find(x[i]) == string::npos) return "nothing";
    }
    return "almost friends";
}

string solve(string x, string y) {
    string ret = "friends";
    int changeNum[2] = {-1, 1};

    if (x.size() == 1) {
        if (y.find(x[0]) == string::npos) {
            if (x[0] == '0') {
                x[0]++;
                if (y.find(x[0]) == string::npos) {
                    ret = "nothing";
                }
                else {
                    ret = "almost friends";
                }
            }
            else if (x[0] - '0' >= 1 && x[0] - '0' < 9) {
                for (int j = 0; j < 2; j++) {
                    if (y.find(x[0] + changeNum[j]) == string::npos &&
                        ret != "almost friends") {
                        ret = "nothing";
                    }
                    else {
                        ret = "almost friends";
                    }
                }
            }
            else {
                string tempX = "10";
                x[0]--;
                for (int i = 0; i < tempX.size(); i++) {
                    if (y.find(tempX[i]) == string::npos &&
                        ret != "almost friends") {
                        ret = "nothing";
                    }
                    else {
                        ret = "almost friends";
                    }
                }
                if (y.find(x[0]) == string::npos &&
                    ret != "almost friends") {
                    ret = "nothing";
                }
                else {
                    ret = "almost friends";
                }
            }
        }
        return ret;
    }

    for (int i = x.size() - 1; i > 0; i--) {
        if (y.find(x[i]) == string::npos) {
            for (int j = 0; j < 2; j++) {
                string tempX = modifyNum(x, i, i - 1, changeNum[j]);
                if (ret != "almost friends") ret = solveModified(tempX, y);
                if (tempX[0] == '0') ret = "nothing";
            }
            return ret;
        }
        if (y.find(x[i - 1]) == string::npos) {
            for (int j = 0; j < 2; j++) {
                string tempX = modifyNum(x, i, i - 1, changeNum[j]);
                if (ret != "almost friends") ret = solveModified(tempX, y);
                if (tempX[0] == '0') ret = "nothing";
            }
            return ret;
        }
    }
    return ret;
}

int main() {
    string x, y, ans, solveX, solveY;
    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        solveX = solve(x, y), solveY = solve(y, x);
        if (solveX == "friends" || solveY == "friends") ans = "friends";
        else if (solveX == "almost friends" || solveY == "almost friends") ans = "almost friends";
        else ans = "nothing";
        cout << ans << "\n";
    }
}