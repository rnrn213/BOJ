#include <bits/stdc++.h>

using namespace std;

vector<string> DNA;

int getHammingDistance(int i, int j) {
    int dist = 0;
    for (int k = 0; k < DNA[i].size(); k++) {
        if (!(DNA[i][k] == DNA[j][k])) dist++;
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > ACGT(M, vector<int>(4, 0));
    for (int i = 0; i < N; i++) {
        string d;
        cin >> d;
        for (int j = 0; j < M; j++) {
            if (d[j] == 'A') ACGT[j][0]++;
            if (d[j] == 'C') ACGT[j][1]++;
            if (d[j] == 'G') ACGT[j][2]++;
            if (d[j] == 'T') ACGT[j][3]++;
        }
        DNA.push_back(d);
    }

    int sumOfHammingDistance = 0;
    string ans = "", nucleotides = "ACGT";
    for (int i = 0; i < ACGT.size(); i++) {
        int max = 0, maxIndex = -1;
        for (int j = 0; j < 4; j++) {
            if (ACGT[i][j] > max) {
                max = ACGT[i][j];
                maxIndex = j;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (j != maxIndex) sumOfHammingDistance += ACGT[i][j];
        }
        ans += nucleotides[maxIndex];
    }
    cout << ans << "\n" << sumOfHammingDistance;
}