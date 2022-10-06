#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > M(1024, vector<int>(1024));

int solve(int y, int x, int size) {
    if (size == 1)
        return M[y][x];

    vector<int> temp;
    temp.push_back(solve(y, x, size / 2));
    temp.push_back(solve(y, x + size / 2, size / 2));
    temp.push_back(solve(y + size / 2, x, size / 2));
    temp.push_back(solve(y + size / 2, x + size / 2, size / 2));

    sort(temp.begin(), temp.end());

    return temp[2];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }

    cout << solve(0, 0, N);
}