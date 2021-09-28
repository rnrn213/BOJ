#include <bits/stdc++.h>

using namespace std;

int N, team1Score = 0, team2Score;
vector< vector<int> > S;

int solve(vector<int>& team1, vector<int>& team2, int memberCount) {
    if (memberCount == N / 2) {
        return abs(team1Score - team2Score);
    }

    int ret = 1000;
    for (int i = *(team1.end() - 1) + 1; i <= N / 2 + (memberCount + 1); i++) {
        for (auto p: team1) {
            team1Score += S[p][i] + S[i][p];
        }
        team1.push_back(i);
        team2.erase(find(team2.begin(), team2.end(), i));
        for (auto p: team2) {
            team2Score -= (S[p][i] + S[i][p]);
        }
        ret = min(ret, solve(team1, team2, memberCount + 1));
        team1.pop_back();
        team2.push_back(i);
        for (auto p: team1) {
            team1Score -= (S[p][i] + S[i][p]);
        }
        for (auto p: team2) {
            team2Score += S[p][i] + S[i][p];
        }
    }

    return ret;
}

int main() {
    cin >> N;
    S = vector< vector<int> >(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    int memberCount = 1;
    vector<int> team1 = {1}, team2;
    for (int i = 2; i <= N; i++) {
        team2.push_back(i);
    }
    for (int i = 0; i < team2.size() - 1; i++) {
        for (int j = i + 1; j <team2.size(); j++) {
            team2Score += S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
        }
    }

    cout << solve(team1, team2, memberCount);
}