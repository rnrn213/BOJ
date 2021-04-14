#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > players;

void input() {
    int white, black;
    while (true) {
        cin >> white >> black;
        if (cin.eof()) break;
        players.push_back(make_pair(white, black));
    }
}

void swap(int i, int j) {
    pair<int, int> temp = players[i];
    players[i] = players[j];
    players[j] = temp;
}

void mySortWhite() {
    for (int i = 0; i < players.size() - 1; i++) {
        for (int j = i + 1; j < players.size(); j++) {
            if (players[i].first < players[j].first) {
                swap(i, j);
            }
        }
    }
}

void mySortBlack() {
    for (int i = 0; i < players.size() - 1; i++) {
        for (int j = i + 1; j < players.size(); j++) {
            if (players[i].second < players[j].second) {
                swap(i, j);
            }
        }
    }
}

int solve() {
    int ret = 0, cnt = 0;
    mySortWhite();
    for (int i = 0; i < players.size(); i++) {
        if (static_cast<double>(players[i].first) / players[i].second - 1.0 >= numeric_limits<double>::epsilon()) {
            ret += players[i].first;
            players.erase(players.begin() + i);
            cnt++;
            i--;
        }
        if (cnt == 15) break;
    }
    mySortBlack();
    for (int i = 0; i < players.size(); i++) {
        if (cnt == 30) break;
        ret += players[i].second;
        cnt++;
    }
    return ret;
}

int main() {
    input();
    cout << solve();
}