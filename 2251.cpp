#include <bits/stdc++.h>

using namespace std;

bool visited[201][201][201];
vector<int> bottle(3), water(3, 0), ans(201, 0);

void solve() {
    visited[water[0]][water[1]][water[2]] = true;

    if (water[0] == 0) ans[water[2]]++;

    for (int i = 0; i < 3; i++) {
        if (water[i] > 0) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;

                int move = (water[i] <= bottle[j] - water[j]) ? water[i] : bottle[j] - water[j];
                water[i] -= move;
                water[j] += move;
                if (!visited[water[0]][water[1]][water[2]]) solve();
                water[j] -= move;
                water[i] += move;
            }
        }
    }
}

int main() {
    cin >> bottle[0] >> bottle[1] >> bottle[2];
    water[2] = bottle[2];

    solve();

    for (int i = 0; i <= 200; i++) {
        if (ans[i] > 0) cout << i << " ";
    }
}