#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair <int, int> > people;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int hp;
        cin >> hp;
        people.push_back(make_pair(hp, 0));
    }
    for (int i = 0; i < N; i++) {
        cin >> people[i].second;
    }
}

void swap(int i, int j) {
    pair<int, int> temp = people[i];
    people[i] = people[j];
    people[j] = temp;
}

void mySort() {
    for (int i = 0; i < N - 1; i++) {
        if (people[i].first == 0) continue;
        for (int j = i + 1; j < N; j++) {
            if (people[j].first == 0) {
                swap(i, j);
            }
            else if ((static_cast<double>(people[j].second) / people[j].first) - 
                        (static_cast<double>(people[i].second) / people[i].first) > numeric_limits<double>::epsilon()) {
                swap(i, j);
            }
        }
    }
}

int solve(int hp, int index) {
    if (hp <= 0) return -1000000000;
    if (index >= N) return 0;

    int happy = 0;
    if (hp - people[index].first > 0) {
        happy = max(solve(hp, index + 1), people[index].second + solve(hp - people[index].first, index + 1));
    }
    else {
        happy = solve(hp, index + 1);
    }
    return happy;
}

int main() {
    input();
    mySort();
    cout << solve(100, 0);
}