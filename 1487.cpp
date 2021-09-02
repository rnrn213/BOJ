#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > people;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int limit, deliveryCharge;
        cin >> limit >> deliveryCharge;

        if (limit <= deliveryCharge) continue;

        people.push_back(make_pair(limit, deliveryCharge));
    }
}

int solve() {
    int maxBenefit = 0, ret = 0;

    for (int i = 0; i < people.size(); i++) {
        int benefit = people[i].first - people[i].second;

        for (int j = i + 1; j < people.size(); j++) {
            if (people[i].first - people[j].second > 0)
                benefit += people[i].first - people[j].second;
        }

        if (benefit > maxBenefit) {
            maxBenefit = benefit;
            ret = people[i].first;
        }
    }

    return ret;
}

int main() {
    input();
    sort(people.begin(), people.end());
    cout << solve();
}