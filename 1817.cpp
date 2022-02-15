#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> book(N);
    for (int i = 0; i < N; i++) {
        cin >> book[i];
    }

    int i = 0, boxCnt = 0;
    while (i < N) {
        int weight = book[i], j = i + 1;
        while (j < N && weight + book[j] <= M) {
            weight += book[j];
            j++;
        }

        boxCnt++;
        i = j;
    }

    cout << boxCnt;
}