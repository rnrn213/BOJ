#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> ladder(101, -1), snake(101, -1);
vector<bool> isVisited(101, false);

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    if (ladder[1] == 100) {
        cout << 0;
        return 0;
    }

    queue<int> normalQ;
    normalQ.push(1);
    isVisited[1] = true;
    if (ladder[1] != -1)
        normalQ.push(ladder[1]);
    int diceCnt = 1;
    while (!normalQ.empty()) {
        queue<int> nextNormalQ;

        while (!normalQ.empty()) {
            int x = normalQ.front();
            normalQ.pop();

            cout << x << "\n";

            for (int i = 1; i <= 6; i++) {
                if (x + i == 100 || ladder[x + i] == 100) {
                    cout << diceCnt;
                    return 0;
                }
                else if (x + i < 100 && !isVisited[x + i]) {
                    if (ladder[x + i] != -1 && !isVisited[ladder[x + i]]) {
                        nextNormalQ.push(ladder[x + i]);
                        isVisited[ladder[x + i]] = true;
                    }
                    else if (snake[x + i] != -1 && !isVisited[ladder[x + i]]) {
                        nextNormalQ.push(snake[x + i]);
                        isVisited[snake[x + i]] = true;
                    }
                    else {
                        nextNormalQ.push(x + i);
                        isVisited[x + i] = true;
                    }
                }
            }
        }
        normalQ = nextNormalQ;

        diceCnt++;
    }
}