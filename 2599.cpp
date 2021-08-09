#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<int, int> > students, ans;

int solve() {
    for (int partialA = 0; partialA <= students[1].second && partialA <= students[0].first; partialA++) {
        int partialC = students[1].second - partialA, partialB = students[2].second - (students[0].first - partialA);
        if (partialB < 0 || partialC < 0 || partialB > students[1].first || partialC > students[2].first) continue;

        if (students[1].first - partialB + students[2].first - partialC == students[0].second) {
            ans.push_back(make_pair(partialA, students[0].first - partialA));
            ans.push_back(make_pair(students[1].first - partialB, partialB));
            ans.push_back(make_pair(students[2].first - partialC, partialC));
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < 3; i++) {
        int boy, girl;
        cin >> boy >> girl;
        students.push_back(make_pair(boy, girl));
    }

    int result = solve();
    cout << result << "\n";
    if (result == 1) {
        for (auto p: ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}