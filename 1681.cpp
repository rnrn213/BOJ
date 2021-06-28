#include <bits/stdc++.h>

using namespace std;

void roundingUpLabel(vector<int>& label, int& len) {
    for (int i = 0; i < label.size() - 1; i++) {
        if (label[i] == 10) {
            label[i + 1]++;
            label[i] = 0;
            len = max(len, i + 1);
        }
        else break;
    }
}

void printMaxLabel(const vector<int>& label) {
    int maxLabel = 0;
    for (int i = label.size() - 1; i >= 0; i--) {
        if (label[i] == 0) continue;

        maxLabel += label[i] * pow(10, i);
    }
    cout << maxLabel;
}

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> label(20, 0);
    label[0] = 1;
    int count = 0, len = 0;
    while (count < N) {
        auto it = find(label.begin(), label.begin() + len + 1, L);
        if (it == label.begin() + len + 1) count++;
        if (count == N) break;
        label[0]++;
        roundingUpLabel(label, len);
    }
    printMaxLabel(label);
}