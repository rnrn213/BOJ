#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > permutations;

void makePermutation(int N, vector<int>& isUsed) {
    if (isUsed.size() == N) {
        permutations.push_back(isUsed);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (find(isUsed.begin(), isUsed.end(), i) == isUsed.end()) {
            isUsed.push_back(i);
            makePermutation(N, isUsed);
            isUsed.pop_back();
        }
    }

    return;
}

int main() {
    int N;
    cin >> N;

    vector<int> isUsed(0);
    makePermutation(N, isUsed);

    for (auto p: permutations) {
        for (auto i: p) {
            cout << i << " ";
        }
        cout << "\n";
    }
}