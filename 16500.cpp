#include <bits/stdc++.h>

using namespace std;

string S, cache[100];
vector<string> A;

void initCache() {
    for (int i = 0; i < 100; i++) {
        cache[i] = "-";
    }
}

void input() {
    int n;
    cin >> S >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        A.push_back(temp);
    }
}

bool isProper(int Sidx, int Aidx) {
    if (S.size() - Sidx < A[Aidx].size()) return false;
    for (int i = 0; i < A[Aidx].size(); i++) {
        if (S[Sidx] != A[Aidx][i]) return false;
        Sidx++;
    }
    return true;
}

string& verifyAnswer(int Sidx, string& a, string&& b) {
    if (a.size() == S.size() - Sidx) return a;
    else return b;
}

string solve(int Sidx) {
    if (Sidx == S.size()) return "";

    string& ret = cache[Sidx];
    if (ret != "-") return ret;
    ret = "";
    for (int i = 0; i < A.size(); i++) {
        if (isProper(Sidx, i)) {
            ret = verifyAnswer(Sidx, ret, A[i] + solve(Sidx + A[i].size()));
        }
    }
    return ret;
}

int getAnswer() {
    string ans = solve(0);

    if (S == ans) return 1;
    else return 0;
}

int main() {
    initCache();
    input();
    cout << getAnswer();
}