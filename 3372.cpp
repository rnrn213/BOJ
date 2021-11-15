#include <bits/stdc++.h>

using namespace std;

int N, board[100][100];
bool isSelected[100][100];
vector<int> oneVector(100, 0), zeroVector(100, 0), minusOneVector(100, 0);
vector< vector< vector<int> > > cache(100, vector< vector<int> >(100, vector<int>(100)));

vector<int> vSum(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() < v2.size())
        return vSum(v2, v1);

    vector<int> ret;
    int carry = 0;
    for (int i = 0; i < v2.size(); i++) {
        int num = v1[i] + v2[i];
        ret.push_back((num + carry) % 10);
        carry = (num + carry) / 10;
    }

    if (v1.size() > v2.size()) {
        for (int i = v2.size(); i < v1.size(); i++) {
            ret.push_back((v1[i] + carry) % 10);
            carry = (v1[i] + carry) / 10;
        }
    }

    if (carry > 0)
        ret.push_back(carry);

    return ret;
}

vector<int> solve(int y, int x) {
    if (y >= N || x >= N)
        return zeroVector;
    if (y == N - 1 && x == N - 1)
        return oneVector;
    if (board[y][x] == 0)
        return zeroVector;

    vector<int>& ret = cache[y][x];
    if (ret != minusOneVector)
        return ret;
    
    return ret = vSum(solve(y + board[y][x], x), solve(y, x + board[y][x]));
}

int main() {
    memset(isSelected, false, 100 * 100 * sizeof(bool));
    oneVector[0] = 1;
    minusOneVector[0] = -1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cache[i][j] = minusOneVector;
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0);

    for (int i = 99; i >= 0; i--) {
        if (i == 0 && cache[0][0][i] == 0)
            cout << 0;
        if (cache[0][0][i] != 0) {
            for (int j = i; j >= 0; j--) {
                cout << cache[0][0][j];
            }
            break;
        }
    }
}