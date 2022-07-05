#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int main() {
    int N;
    cin >> N;
    vector< vector<int> > space(N, vector<int>(N));
    pair<int, int> babySharkPosition;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];

            if (space[i][j] == 9)
                babySharkPosition = make_pair(i, j);
        }
    }

    int babySharkSize = 2, eatenFishCnt = 0, totalTime = 0, t = 1;
    vector< pair<int, int> > edibleFish;
    vector< vector<bool> > isVisited(N, vector<bool>(N, false));
    queue< pair<int, int> > q;
    q.push(babySharkPosition);
    isVisited[babySharkPosition.first][babySharkPosition.second] = true;
    space[babySharkPosition.first][babySharkPosition.second] = 0;
    while (!q.empty()) {
        queue< pair<int, int> > nextQ, nextUnderQ;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                if ((p.first + direction[i][0] >= 0 && p.first + direction[i][0] < N) &&
                    (p.second + direction[i][1] >= 0 && p.second + direction[i][1] < N) &&
                    space[p.first + direction[i][0]][p.second + direction[i][1]] <= babySharkSize &&
                    !isVisited[p.first + direction[i][0]][p.second + direction[i][1]]) {

                    nextQ.push(make_pair(p.first + direction[i][0], p.second + direction[i][1]));

                    if (space[p.first + direction[i][0]][p.second + direction[i][1]] != 0 &&
                        space[p.first + direction[i][0]][p.second + direction[i][1]] < babySharkSize) {
                        edibleFish.push_back(make_pair(p.first + direction[i][0], p.second + direction[i][1]));
                    }

                    isVisited[p.first + direction[i][0]][p.second + direction[i][1]] = true;
                }
            }
        }

        if (edibleFish.size() > 0) {
            sort(edibleFish.begin(), edibleFish.end());
            int temp = abs(babySharkPosition.first - edibleFish[0].first) + abs(babySharkPosition.second - edibleFish[0].second);
            totalTime += t;
            babySharkPosition = edibleFish[0];
            space[babySharkPosition.first][babySharkPosition.second] = 0;
            t = 0;

            eatenFishCnt++;
            if (eatenFishCnt == babySharkSize) {
                babySharkSize++;
                eatenFishCnt = 0;
            }

            while (!nextQ.empty()) {
                nextQ.pop();
            }
            nextQ.push(babySharkPosition);
            isVisited = vector< vector<bool> >(N, vector<bool>(N, false));
            isVisited[babySharkPosition.first][babySharkPosition.second] = true;

            edibleFish.clear();
        }

        q = nextQ;
        t++;
    }

    cout << totalTime;
}