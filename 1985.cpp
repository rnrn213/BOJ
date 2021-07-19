#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
vector<int> getNumbers(string n) {
    vector<int> ret;
    for (int i = 0; i < n.size(); i++) {
        ret.push_back(n[i] - '0');
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
}

vector<string> modifyNum(string num, int idx) {
    int changeValue[2] = {-1, 1};
    vector<string> ret;
    for (int i = 0; i < 2; i++) {
        string modifiedNum = num;
        modifiedNum[idx] += changeValue[i];
        modifiedNum[idx - 1] -= changeValue[i];
        for (int j = idx; j > 0; j--) {
            if (modifiedNum[j] - '0' == -1) {
                modifiedNum[j] = '9';
                modifiedNum[j - 1]--;
            }
            if (modifiedNum[j] - '0' == 10) {
                modifiedNum[j] = '0';
                modifiedNum[j - 1]++;
            }
        }
        if (modifiedNum[0] - '0' == 10) {
            modifiedNum[0] = '0';
            modifiedNum = "1" + modifiedNum;
        }
        ret.push_back(modifiedNum);
    }
    return ret;
}

int main() {
    vector<string> num(2);
    vector< vector<int> > nums(2);
    for (int i = 0; i < 3; i++) {
        cin >> num[0] >> num[1];
        for (int j = 0; j < 2; j++) {
            nums[j] = getNumbers(num[j]);
        }
        if (nums[0] == nums[1]) {
            cout << "friends\n";
            continue;
        }
        vector< vector<int> > saveNums = nums;

        for (int j = 0; j < nums[0].size(); j++) {
            auto it = find(nums[1].begin(), nums[1].end(), nums[0][j]);
            if (it != nums[1].end()) {
                nums[0].erase(nums[0].begin() + j);
                j--;
                nums[1].erase(it);
            }
        }

        if (nums[0].size() != 0) {
            bool isAlmostFriends = false;
            for (int j = num[0].size() - 1; j > 0; j--) {
                auto it = find(nums[0].begin(), nums[0].end(), num[0][j] - '0');
                if (it != nums[0].end()) {
                    vector<string> modifiedNums = modifyNum(num[0], j);
                    for (int k = 0; k < modifiedNums.size(); k++) {
                        if (saveNums[1] == getNumbers(modifiedNums[k]) && 
                            modifiedNums[k][0] != '0') {
                            isAlmostFriends = true;
                            break;
                        }
                    }
                    break;
                }
                it = find(nums[0].begin(), nums[0].end(), num[0][j - 1] - '0');
                if (it != nums[0].end()) {
                    vector<string> modifiedNums = modifyNum(num[0], j);
                    for (int k = 0; k < modifiedNums.size(); k++) {
                        if (saveNums[1] == getNumbers(modifiedNums[k]) && 
                            modifiedNums[k][0] != '0') {
                            isAlmostFriends = true;
                            break;
                        }
                    }
                    if (isAlmostFriends) break;
                }

            }
            if (isAlmostFriends) {
                cout << "almost friends\n";
                continue;
            }
        }
        if (nums[1].size() != 0) {
            bool isAlmostFriends = false;
            for (int j = num[1].size() - 1; j > 0; j--) {
                auto it = find(nums[1].begin(), nums[1].end(), num[1][j] - '0');
                if (it != nums[1].end()) {
                    vector<string> modifiedNums = modifyNum(num[1], j);
                    for (int k = 0; k < modifiedNums.size(); k++) {
                        if (saveNums[0] == getNumbers(modifiedNums[k]) && 
                            modifiedNums[k][0] != '0') {
                            isAlmostFriends = true;
                            break;
                        }
                    }
                    break;
                }
                it = find(nums[1].begin(), nums[1].end(), num[1][j - 1] - '0');
                if (it != nums[1].end()) {
                    vector<string> modifiedNums = modifyNum(num[1], j);
                    for (int k = 0; k < modifiedNums.size(); k++) {
                        if (saveNums[0] == getNumbers(modifiedNums[k]) && 
                            modifiedNums[k][0] != '0') {
                            isAlmostFriends = true;
                            break;
                        }
                    }
                    if (isAlmostFriends) break;
                }
            }
            if (isAlmostFriends) {
                cout << "almost friends\n";
                continue;
            }
        }
        cout << "nothing\n";
=======
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
>>>>>>> 8acdd685c1fb43161aad9f56e0fb62d275c8fd02
    }
}