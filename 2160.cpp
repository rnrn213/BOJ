#include <bits/stdc++.h>

using namespace std;

vector< vector< string > > pictures;

int countDifference(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (pictures[a][i][j] != pictures[b][i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector< string > picture;
        for (int j = 0; j < 5; j++) {
            string line;
            cin >> line;
            picture.push_back(line);
        }
        pictures.push_back(picture);
    }

    int a, b, minDiff = 50;
    for (int i = 0; i < pictures.size() - 1; i++) {
        for (int j = i + 1; j < pictures.size(); j++) {
            int diff = countDifference(i, j);
            if (diff < minDiff) {
                minDiff = diff;
                a = i + 1;
                b = j + 1;
            }
        }
    }
    cout << a << " " << b;
}