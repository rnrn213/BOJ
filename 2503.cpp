#include <bits/stdc++.h>

using namespace std;

pair<int, int> bullsAndCows(const string& a, const string& b) {
    int S = 0, B = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && a[i] == b[j]) S++;
            if (i != j && a[i] == b[j]) B++;
        }
    }
    return make_pair(S, B);
}

int main() {
    vector<string> youngSu;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (i != j && i != k && j != k) {
                    youngSu.push_back(to_string(i * pow(10, 2) + j * pow(10, 1) + k));
                }
            }
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string minHyuk;
        int S, B;
        cin >> minHyuk >> S >> B;

        vector<string> temp;
        for (int j = 0; j < youngSu.size(); j++) {
            pair<int, int> result = bullsAndCows(youngSu[j], minHyuk);
            if (result.first == S && result.second == B) {
                temp.push_back(youngSu[j]);
            }
        }
        youngSu = temp;
    }
    cout << youngSu.size();
}