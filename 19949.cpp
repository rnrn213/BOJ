#include <bits/stdc++.h>

using namespace std;

vector<int> youngGae(10, 0), ans(10);

int getScore() {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        if (youngGae[i] == ans[i])
            score++;
    }

    return score;
}

int solve(int idx) {
    if (idx == 10) {
        if (getScore() >= 5)
            return 1;
        else
            return 0;
    }

    int ret = 0;
    for (int i = 1; i <= 5; i++) {
        if (idx >= 2 && youngGae[idx - 2] == i && youngGae[idx - 1] == i)
            continue;
        
        youngGae[idx] = i;
        ret += solve(idx + 1);
        youngGae[idx] = 0;
    }

    return ret;
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> ans[i];
    }

    cout << solve(0);
}