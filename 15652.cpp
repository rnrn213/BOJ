#include <bits/stdc++.h>

using namespace std;

int N, M;

void getProgression(vector<int>& progression) {
    if (progression.size() == M) {
        for (auto n: progression) {
            cout << n << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = *(progression.end() - 1); i <= N; i++) {
        progression.push_back(i);
        getProgression(progression);
        progression.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        vector<int> progression = {i};
        getProgression(progression);
    }
}