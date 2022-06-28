#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<int> > paper, direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int tetromino(vector< pair<int, int> >& isVisiting, vector< vector<bool> >& isVisited) {
    if (isVisiting.size() == 4) {
        int sum = 0;
        for (pair<int, int> p : isVisiting) {
            sum += paper[p.first][p.second];
        }

        return sum;
    }

    int maxSum = 0;
    vector< pair<int, int> > next;
    for (pair<int, int> p : isVisiting) {
        for (int i = 0; i < 4; i++) {
            if ((p.first + direction[i][0] >= 0 && p.first + direction[i][0] < N) &&
                (p.second + direction[i][1] >= 0 && p.second + direction[i][1] < M) &&
                !isVisited[p.first + direction[i][0]][p.second + direction[i][1]]) {

                next.push_back(make_pair(p.first + direction[i][0], p.second + direction[i][1]));
            }
        }
    }

    sort(next.begin(), next.end());
    next.erase(unique(next.begin(), next.end()), next.end());

    for (pair<int, int> p : next) {
        isVisiting.push_back(p);
        isVisited[p.first][p.second] = true;
        maxSum = max(maxSum, tetromino(isVisiting, isVisited));
        isVisited[p.first][p.second] = false;
        isVisiting.pop_back();
    }

    return maxSum;
}

int main() {
    cin >> N >> M;
    paper = vector< vector<int> >(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    vector< vector<bool> > isVisited(N, vector<bool>(M, false));
    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector< pair<int, int> > isVisiting(1, make_pair(i, j));
            isVisited[i][j] = true;

            int sum = tetromino(isVisiting, isVisited);

            isVisited[i][j] = false;

            maxSum = (maxSum > sum) ? maxSum : sum;
        }
    }

    cout << maxSum;
}