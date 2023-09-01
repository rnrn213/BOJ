#include <bits/stdc++.h>

using namespace std;

int N, k = 0;
vector<string> draw[11];

int main() {
    cin >> N;

    draw[0].push_back("  *  ");
    draw[0].push_back(" * * ");
    draw[0].push_back("*****");

    int temp = N / 3;
    while (temp > 1) {
        temp /= 2;
        k++;
    }

    for (int i = 1; i <= k; i++) {
        int sp = 3 * pow(2, i - 1);
        string ws = "";
        for (int j = 0; j < sp; j++)
            ws += " ";
        
        for (int j = 0; j < draw[i - 1].size(); j++) {
            draw[i].push_back(ws + draw[i - 1][j] + ws);
        }

        for (int j = 0; j < draw[i - 1].size(); j++) {
            draw[i].push_back(draw[i - 1][j] + " " + draw[i - 1][j]);
        }
    }

    for (int i = 0; i < draw[k].size(); i++) {
        cout << draw[k][i] << "\n";
    }
}