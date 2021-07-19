#include <bits/stdc++.h>

using namespace std;

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
        
        bool isAlmostFriends = false;
        for (int j = 0; j < 2; j++) {
            for (int k = num[j].size() - 1; k > 0; k--) {
                vector<string> modifiedNums = modifyNum(num[j], k);
                for (int n = 0; n < modifiedNums.size(); n++) {
                    if (nums[!j] == getNumbers(modifiedNums[n]) && 
                        modifiedNums[n][0] != '0') {
                        isAlmostFriends = true;
                    }
                }
            }
        }
        if (isAlmostFriends) cout << "almost friends\n";
        else cout << "nothing\n";
    }
}