#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector< pair<int, int> > people(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> people[i].first >> people[i].second;
    }
    vector<int> body(N);
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (people[i].first < people[j].first && 
                        people[i].second < people[j].second) {
                    cnt++;
                }
            }
        }
        body[i] = cnt + 1;
    }
    for (auto grade: body) cout << grade << " ";
}