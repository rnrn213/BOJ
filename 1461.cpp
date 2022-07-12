#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> leftBooks(1, 0), rightBooks(1, 0);
    for (int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        if (pos < 0)
            leftBooks.push_back(-1 * pos);
        else
            rightBooks.push_back(pos);
    }

    sort(leftBooks.begin(), leftBooks.end());
    sort(rightBooks.begin(), rightBooks.end());

    int totalSteps = 0;
    for (int i = (leftBooks.size() - 1) % M; i < leftBooks.size(); i += M) {
        totalSteps += 2 * leftBooks[i];
    }
    for (int i = (rightBooks.size() - 1) % M; i < rightBooks.size(); i += M) {
        totalSteps += 2 * rightBooks[i];
    }

    if (*(leftBooks.end() - 1) > *(rightBooks.end() - 1)) {
        totalSteps -= *(leftBooks.end() - 1);
    }
    else {
        totalSteps -= *(rightBooks.end() - 1);
    }

    cout << totalSteps;
}