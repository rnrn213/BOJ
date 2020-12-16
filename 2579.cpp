#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int* stair = new int[N + 1];
    stair[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }
    int* maxScore = new int[N + 1];
    maxScore[0] = 0;
    maxScore[1] = stair[1];
    bool isThird = false;
    if (N > 1) {
        maxScore[2] = stair[1] + stair[2];
        isThird = true;
    }
    for (int i = 3; i <= N; i++) {
        maxScore[i] = max({maxScore[i - 1] + stair[i], maxScore[i - 2] + stair[i], maxScore[i - 3] + stair[i - 1] + stair[i]});
        if (isThird && maxScore[i] == maxScore[i - 1] + stair[i]) {
            maxScore[i] = max(maxScore[i - 2] + stair[i], maxScore[i - 3] + stair[i - 1] + stair[i]);
        }

        if (maxScore[i] == maxScore[i - 2] + stair[i]) {
            isThird = false;
        }
        else {
            isThird = true;
        }
    }
    cout << maxScore[N];
}