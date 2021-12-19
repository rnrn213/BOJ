#include <bits/stdc++.h>

using namespace std;

pair<int, int> getMinMax(const string& A, const string& B) {
    pair<int, int> ret;
    string tempA = A, tempB = B;
    for (int i = 0; i < tempA.size(); i++)
        if (tempA[i] == '6')
            tempA[i] = '5';
    for (int i = 0; i < tempB.size(); i++)
        if (tempB[i] == '6')
            tempB[i] = '5';
    ret.first = stoi(tempA) + stoi(tempB);

    tempA = A, tempB = B;
    for (int i = 0; i < tempA.size(); i++)
        if (tempA[i] == '5')
            tempA[i] = '6';
    for (int i = 0; i < tempB.size(); i++)
        if (tempB[i] == '5')
            tempB[i] = '6';
    ret.second = stoi(tempA) + stoi(tempB);

    return ret;
}

int main() {
    int A, B;
    cin >> A >> B;
    pair<int, int> minMax = getMinMax(to_string(A), to_string(B));

    cout << minMax.first << " " << minMax.second;
}