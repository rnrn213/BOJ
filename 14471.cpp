#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< pair<int, int> > pointCard;
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        pair<int, int> card;
        cin >> card.first >> card.second;
        pointCard.push_back(card);
    }
    sort(pointCard.begin(), pointCard.end(), greater<>());

    int i = 0, cost = 0;
    while (i < M - 1) {
        if (pointCard[i].first < N)
            cost += N - pointCard[i].first;
        i++;
    }

    cout << cost;
}