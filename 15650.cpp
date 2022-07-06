#include <bits/stdc++.h>

using namespace std;

int N, M;

void getProgression(vector<int>& v) {
    if (v.size() == M) {
        for (auto n: v) {
            cout << n << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = *(v.end() - 1) + 1; i <= N; i++) {
        v.push_back(i);
        getProgression(v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        vector<int> v = {i};
        getProgression(v);
    }
}