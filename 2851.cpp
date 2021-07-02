#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> mushrooms(10, 0), score(10, 0);
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> mushrooms[i];
        sum += mushrooms[i];
        score[i] = sum;
    }
    sort(score.begin(), score.end(), greater<int>());
    int diff = 100, ansIndex;
    for (int i = 0; i < score.size(); i++) {
        if (abs(score[i] - 100) < diff) {
            diff = abs(score[i] - 100);
            ansIndex = i;
        }
    }
    cout << score[ansIndex];
}