#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Z, M;
    cin >> N >> Z >> M;
    vector<bool> hurdle(N + 1, false);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        hurdle[num] = true;
    }

    for (int K = 1; K < N; K++) {
        bool isAnswer = false;
        int num = 1 + K;
        while (num != 1) {
            if (hurdle[num])
                break;
            if (num == Z) {
                isAnswer = true;
                break;
            }

            num += K;
            if (num > N)
                num = num % N;
        }

        if (isAnswer) {
            cout << K;
            break;
        }
    }
}