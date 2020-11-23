#include <bits/stdc++.h>

using namespace std;

void add(vector<int>& C, const vector<int>& A, const vector<int>& B) {
    if (A.size() > B.size()) {
        int carry = 0;
        int i;
        for (i = 0; i < B.size(); i++) {
            C.push_back((A[i] + B[i] + carry) % 10);
            carry = (A[i] + B[i] + carry) / 10;
        }
        while (i < A.size()) {
            C.push_back((A[i] + carry) % 10);
            carry = (A[i] + carry) / 10;
            i++;
        }
        if (carry == 1) {
            C.push_back(1);
        }
    }
    else {
        int carry = 0;
        int i;
        for (i = 0; i < A.size(); i++) {
            C.push_back((A[i] + B[i] + carry) % 10);
            carry = (A[i] + B[i] + carry) / 10;
        }
        while (i < B.size()) {
            C.push_back((B[i] + carry) % 10);
            carry = (B[i] + carry) / 10;
            i++;
        }
        if (carry == 1) {
            C.push_back(1);
        }
    }
}

int main() {
    string n1, n2;
    cin >> n1 >> n2;

    bool isANeg = false;
    bool isBNeg = false;
    int aSize = n1.size();
    int bSize = n2.size();
    if (n1[0] == '-') {
        n1.erase(0);
        isANeg = true;
        aSize--;
    }
    if (n2[0] == '-') {
        n2.erase(0);
        isBNeg = true;
        bSize--;
    }
    bool AisBig = false;
    if (n1.compare(n2) > 0) AisBig = true;
    vector<int> A;
    for (auto c: n1) {
        A.push_back(static_cast<int>(c - '0'));
    }
    vector<int> B;
    for (auto c: n2) {
        B.push_back(static_cast<int>(c - '0'));
    }

    if (!isANeg && !isBNeg) {

    }
    else if (isANeg && !isBNeg) {

    }
    else if (!isANeg && isBNeg) {

    }
    else {

    }
}