#include <bits/stdc++.h>

using namespace std;

vector<char> ans;
bool isFinished = false;

//overflow 발생
int s(int x, int index = 814) {
    if (index <= 4) {
        return ((static_cast<int>(pow(x, index)) % 20200429) * (static_cast<int>(pow(x, index)) % 20200429)) % 20200429;
    }

    return (s(x, index / 2) * s(x, index / 2 + index % 2)) % 20200429;
}

void solve(int y, vector<char>& v) {
    if (y == 20200402) {
        ans = v;
        isFinished = true;
        return;
    }

    for (int i = 48; i <= 57; i++) {
        if (!isFinished) {
            v.push_back(i);
            solve(((y % 20200429) + s(i)) % 20200429, v);
            v.pop_back();
        }
    }
    for (int i = 65; i <= 90; i++) {
        if (!isFinished) {
            v.push_back(i);
            solve(((y % 20200429) + s(i)) % 20200429, v);
            v.pop_back();
        }
    }
    for (int i = 97; i <= 122; i++) {
        if (!isFinished) {
            v.push_back(i);
            solve(((y % 20200429) + s(i)) % 20200429, v);
            v.pop_back();
        }
    }
}

int main() {
    vector<char> v;
    solve(0, v);

    for (auto c: ans) {
        cout << c;
    }
}