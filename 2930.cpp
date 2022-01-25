#include <bits/stdc++.h>

using namespace std;

int R, N, score = 0, maxScore = 0;
string sang, *friends;
vector< vector<int> > F;

int main() {
    cin >> R >> sang >> N;
    friends = new string[N];
    F = vector< vector<int> >(R, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        cin >> friends[i];

        for (int j = 0; j < R; j++) {
            if (friends[i][j] == 'S') {
                if (sang[j] == 'S')
                    score += 1;
                else if (sang[j] == 'R')
                    score += 2;
                
                F[j][0]++;
            }
            if (friends[i][j] == 'P') {
                if (sang[j] == 'P')
                    score += 1;
                else if (sang[j] == 'S')
                    score += 2;
                
                F[j][1]++;
            }
            if (friends[i][j] == 'R') {
                if (sang[j] == 'P')
                    score += 2;
                else if (sang[j] == 'R')
                    score += 1;

                F[j][2]++;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        maxScore += max({F[i][0] * 2 + F[i][2], F[i][1] * 2 + F[i][0], F[i][2] * 2 + F[i][1]});;
    }

    cout << score << "\n" << maxScore;
}