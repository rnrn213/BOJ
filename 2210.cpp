#include <bits/stdc++.h>

using namespace std;

vector< vector<string> > board(5, vector<string>(5));

void getNums(vector<string>& nums, int y, int x, string s) {
    if (s.size() == 6) {
        nums.push_back(s);
        return;
    }

    if (y > 0) {
        string tempS = s;
        s += board[y - 1][x];
        getNums(nums, y - 1, x, s);
        s = tempS;
    }
    if (y < 4) {
        string tempS = s;
        s += board[y + 1][x];
        getNums(nums, y + 1, x, s);
        s = tempS;
    }
    if (x > 0) {
        string tempS = s;
        s += board[y][x - 1];
        getNums(nums, y, x - 1, s);
        s = tempS;
    }
    if (x < 4) {
        string tempS = s;
        s += board[y][x + 1];
        getNums(nums, y, x + 1, s);
        s = tempS;
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    vector<string> nums;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string s = board[i][j];
            getNums(nums, i, j, s);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    cout << nums.size();
}