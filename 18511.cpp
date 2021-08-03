#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> K;

vector<int> getNextIdx(const vector<int>& idx) {
    vector<int> temp = idx;
    int i = 0;
    while (i < temp.size() && temp[i] == K.size() - 1) {
        temp[i] = 0;
        i++;
    }
    if (i == temp.size()) {
        temp.push_back(0);
        return temp;
    }
    int j = 0;
    for (j = 0; j < K.size() - 1; j++) {
        if (temp[i] == j) break;
    }
    temp[i] = j + 1;

    return temp;
}

int getNum(const vector<int>& idx) {
    int num = 0;
    for (int i = 0; i < idx.size(); i++) {
        num += K[idx[i]] * pow(10, i);
    }
    return num;
}

int solve() {
    vector<int> idx = {0};
    int ret = getNum(idx);
    while (N >= getNum(getNextIdx(idx))) {
        idx = getNextIdx(idx);
        ret = getNum(idx);
    }
    return ret;
}

int main() {
    int KSize;
    cin >> N >> KSize;
    for (int i = 0; i < KSize; i++) {
        int element;
        cin >> element;
        K.push_back(element);
    }
    sort(K.begin(), K.end());

    cout << solve();
}