#include <bits/stdc++.h>

using namespace std;

int N, bugs[21], newBugs[21];

void input() {
    cin >> N;
}

void calculateBugs() {
    bugs[1] = 1, bugs[2] = 2, bugs[3] = 4, bugs[4] = 7;
    newBugs[1] = 1, newBugs[2] = 1, newBugs[3] = 2, newBugs[4] = 4;

    for (int i = 5; i <= 20; i++) {
        if (i % 2 == 1) bugs[i] = bugs[i - 1] * 2;
        else bugs[i] = bugs[i - 1] * 2 - newBugs[i - 3] - newBugs[i - 4];
        newBugs[i] = bugs[i - 1];
    }
}

int main() {
    input();
    calculateBugs();
    cout << bugs[N];
}