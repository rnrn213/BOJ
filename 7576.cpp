#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int M, N;
    cin >> M >> N;
    vector< vector<int> > box(N, vector<int>(M));
    queue< tuple<int, int> > q;
    int cntZero = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push(make_tuple(i, j));
            else if (box[i][j] == 0)
                cntZero++;
        }
    }

    int day = 0;
    while (!q.empty()) {
        queue< tuple<int, int> > nextQ;

        while (!q.empty()) {
            tuple<int, int> t = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                if ((get<0>(t) + direction[i][0] >= 0 && get<0>(t) + direction[i][0] < N) &&
                    (get<1>(t) + direction[i][1] >= 0 && get<1>(t) + direction[i][1] < M) &&
                    box[get<0>(t) + direction[i][0]][get<1>(t) + direction[i][1]] == 0) {
                    
                    nextQ.push(make_tuple(get<0>(t) + direction[i][0], get<1>(t) + direction[i][1]));
                    box[get<0>(t) + direction[i][0]][get<1>(t) + direction[i][1]] = 1;
                    cntZero--;
                }
            }
        }

        q = nextQ;
        day++;
    }

    if (cntZero > 0)
        cout << -1;
    else
        cout << day - 1;
}