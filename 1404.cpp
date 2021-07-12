#include <bits/stdc++.h>

using namespace std;

int main() {
    int winningRate[8][8];
    vector<double> winChance(8, 1.0);

    for (int i = 0; i < 8; i++) {
        winningRate[i][i] = 0;
        for (int j = i + 1; j < 8; j++) {
            int w;
            cin >> w;
            winningRate[i][j] = w;
            winningRate[j][i] = 100 - w;
        }
    }

    for (int a = 2; a <= 8; a *= 2) {
        vector<double> tempWinChance = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        for (int i = 0; i < 8; i += a) {
            for (int j = 0; j < a / 2; j++) {
                for (int k = a / 2; k < a; k++) {
                    tempWinChance[i + j] += winChance[i + j] * (winChance[i + k] * (static_cast<double>(winningRate[i + j][i + k]) / 100));
                    tempWinChance[i + k] += winChance[i + k] * (winChance[i + j] * (static_cast<double>(winningRate[i + k][i + j]) / 100));
                }
            }
        }
        /* cout << "tempWinChance = {";
        for (auto p: tempWinChance) {
            cout << p << " ";
        }
        cout << "}\n"; */

        winChance = tempWinChance;
    }
    cout.precision(9);
    for (int i = 0; i < 8; i++) {
        cout << winChance[i] << " ";
    }
}