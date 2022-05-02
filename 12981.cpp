#include <bits/stdc++.h>

using namespace std;

const int EMPTY = 99999999;

int main() {
    int balls[3];
    cin >> balls[0] >> balls[1] >> balls[2];

    int boxCnt = 0, minBall = min({balls[0], balls[1], balls[2]});
    boxCnt += minBall;
    for (int& ball: balls) {
        ball -= minBall;
    }

    for (int& ball: balls) {
        boxCnt += ball / 3;
        ball = ball % 3;
    }

    if ((balls[0] == 1 && balls[1] == 1) || (balls[0] == 1 && balls[2] == 1) || (balls[1] == 1 && balls[2] == 1)) {
        boxCnt++;
    }
    else {
        for (int ball: balls) {
            if (ball % 3)
                boxCnt++;
        }
    }

    cout << boxCnt;
}