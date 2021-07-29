#include <bits/stdc++.h>

using namespace std;

int countBeach(const vector< vector<char> >& beachMap) {
    int countBeach = 0;
    for (int i = 0; i < beachMap.size(); i++) {
        for (int j = 0; j < beachMap[i].size(); j++) {
            if (i % 2 == 0) {
                if (i > 0 && beachMap[i][j] != beachMap[i - 1][j]) {
                    countBeach++;
                }
                if (j < beachMap[i].size() - 1 && beachMap[i][j] != beachMap[i][j + 1]) {
                    countBeach++;
                }
                if (i < beachMap.size() - 1 && beachMap[i][j] != beachMap[i + 1][j]) {
                    countBeach++;
                }
            }
            else {
                if (j == beachMap[i].size() - 1) continue;
                if (beachMap[i][j] != beachMap[i - 1][j + 1]) {
                    countBeach++;
                }
                if (beachMap[i][j] != beachMap[i][j + 1]) {
                    countBeach++;
                }
                if (i < beachMap.size() - 1 && beachMap[i][j] != beachMap[i + 1][j + 1]) {
                    countBeach++;
                }
            }
        }
    }
    return countBeach;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<char> > beachMap(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> beachMap[i][j];
        }
    }
    cout << countBeach(beachMap);
}