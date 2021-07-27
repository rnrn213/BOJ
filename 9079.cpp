#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > allH = {{'H', 'H', 'H'}, {'H', 'H', 'H'}, {'H', 'H', 'H'}}, 
                        allT = {{'T', 'T', 'T'}, {'T', 'T', 'T'}, {'T', 'T', 'T'}};


int getAnswer(vector< vector<char> >& coins, int depth) {
    if (coins == allH || coins == allT) return depth;
    if (depth == 7) return 100;

    int ret = 10000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (coins[i][j] == 'H') coins[i][j] = 'T';
            else coins[i][j] = 'H';
        }
        ret = min(ret, getAnswer(coins, depth + 1));
        for (int j = 0; j < 3; j++) {
            if (coins[i][j] == 'H') coins[i][j] = 'T';
            else coins[i][j] = 'H';
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (coins[j][i] == 'H') coins[j][i] = 'T';
            else coins[j][i] = 'H';
        }
        ret = min(ret, getAnswer(coins, depth + 1));
        for (int j = 0; j < 3; j++) {
            if (coins[j][i] == 'H') coins[j][i] = 'T';
            else coins[j][i] = 'H';
        }
    }

    for (int i = 0; i < 3; i++) {
        if (coins[i][i] == 'H') coins[i][i] = 'T';
        else coins[i][i] = 'H';
    }
    ret = min(ret, getAnswer(coins, depth + 1));
    for (int i = 0; i < 3; i++) {
        if (coins[i][i] == 'H') coins[i][i] = 'T';
        else coins[i][i] = 'H';
    }

    for (int i = 0; i < 3; i++) {
        if (coins[i][2 - i] == 'H') coins[i][2 - i] = 'T';
        else coins[i][2 - i] = 'H';
    }
    ret = min(ret, getAnswer(coins, depth + 1));
    for (int i = 0; i < 3; i++) {
        if (coins[i][2 - i] == 'H') coins[i][2 - i] = 'T';
        else coins[i][2 - i] = 'H';
    }

    return ret;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector< vector<char> > coins(3, vector<char>(3));
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> coins[j][k];
            }
        }

        int ans = getAnswer(coins, 0);
        if (ans == 100) ans = -1;
        cout << ans << "\n";
    }
}