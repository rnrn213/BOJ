#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > direction = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} };

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int M, N, H;
    cin >> M >> N >> H;
    vector< vector< vector<int> > > box(H, vector< vector<int> >(N, vector<int>(M)));
    queue< tuple<int, int, int> > q;
    int cntZero = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    q.push(make_tuple(i, j, k));
                else if (box[i][j][k] == 0)
                    cntZero++;
            }
        }
    }

    int day = 0;
    while (!q.empty()) {
        queue< tuple<int, int, int> > nextQ;

        while (!q.empty()) {
            tuple<int, int, int> t = q.front();
            q.pop();
            
            for (int i = 0; i < 6; i++) {
                if ((get<0>(t) + direction[i][0] >= 0 && get<0>(t) + direction[i][0] < H) &&
                    (get<1>(t) + direction[i][1] >= 0 && get<1>(t) + direction[i][1] < N) &&
                    (get<2>(t) + direction[i][2] >= 0 && get<2>(t) + direction[i][2] < M) &&
                    box[get<0>(t) + direction[i][0]][get<1>(t) + direction[i][1]][get<2>(t) + direction[i][2]] == 0) {
                    
                    nextQ.push(make_tuple(get<0>(t) + direction[i][0], get<1>(t) + direction[i][1], get<2>(t) + direction[i][2]));
                    box[get<0>(t) + direction[i][0]][get<1>(t) + direction[i][1]][get<2>(t) + direction[i][2]] = 1;
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