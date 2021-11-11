#include <bits/stdc++.h>

using namespace std;

int strokes[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
string A, B;

vector<int> strokes1, strokes2;

string solve(vector<int>& v) {
    int limit = v.size();
    while (limit > 1) {
        for (int i = 0; i < limit - 1; i++) {
            v[i] = (v[i] + v[i + 1]) % 10;
        }
        limit--;
    }

    return to_string(v[0]);
}

int main() {
    cin >> A >> B;
    string AB = "";
    for (int i = 0; i < A.size(); i++) {
        AB += A[i];
        AB += B[i];
    }
    vector<int> ABStrokes;
    for (auto a: AB)
        ABStrokes.push_back(strokes[a - 'A']);

    int i1 = 0, i2 = ABStrokes.size() - 1;
    while (i1 < ABStrokes.size() - 1 && i2 > 0) {
        strokes1.push_back(ABStrokes[i1++]);
        strokes2.push_back(ABStrokes[i2--]);
    }

    cout << solve(strokes1) + solve(strokes2);
}