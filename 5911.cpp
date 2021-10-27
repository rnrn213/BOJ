#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, B;
    cin >> N >> B;
    vector< pair<int, int> > friends;
    for (int i = 0; i < N; i++) {
        int P, S;
        cin >> P >> S;
        friends.push_back(make_pair(P, S));
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (friends[i].first + friends[i].second > friends[j].first + friends[j].second) {
                pair<int, int> temp = friends[i];
                friends[i] = friends[j];
                friends[j] = temp;
            }
        }
    }

    int maxCnt = 0;
    for (int discountIdx = 0; discountIdx < N; discountIdx++) {
        int cnt = 0, tempB = B;
        if (friends[discountIdx].first / 2 + friends[discountIdx].second <= tempB) {
            cnt++;
            tempB -= friends[discountIdx].first / 2 + friends[discountIdx].second;
            for (int i = 0; i < N; i++) {
                if (i == discountIdx)
                    continue;
                if (friends[i].first + friends[i].second > tempB)
                    break;
                
                tempB -= friends[i].first + friends[i].second;
                cnt++;
            }
        }
        if (cnt > maxCnt)
            maxCnt = cnt;
    }

    cout << maxCnt;
}