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

void sub(vector<int>& C, const vector<int>& A, const vector<int>& B) {
    for (int i = B.size() - 1; i >= 0; i--) {
        if (A[i] < B[i]) {
            int j = i + 1;
            while (C[j] == 0 && j <= C.size() - 1) {
                j++;
            }
            C[j]--;
            j--;
            while (j > i) {
                C[j] = 9;
                j--;
            }
            C[i] = A[i] + 10 - B[i];
        }
        else {
            C[i] = A[i] - B[i];
        }
    }
    vector<int>::iterator it = C.end() - 1;
    while (*it == 0) {
        it = C.erase(it);
        it--;
    }
    if (C.size() == 0) {
        C.push_back(0);
    }
}

void multiple(vector<int>& C, const vector<int>& A, const vector<int>& B) {
    for (int i = 0; i < B.size(); i++) {
        int carry = 0;
        int j;
        for (j = 0; j < A.size(); j++) {
            C[j + i] += (A[j] * B[i] + carry) % 10;
            carry = (A[j] * B[i] + carry) / 10;
            if (C[j + i] >= 10) {
                carry += C[j + i] / 10;
                C[j + i] = C[j + i] % 10;
            }
        }
        if (carry != 0) {
            C[j + i] += carry;
        }
    }
    vector<int>::iterator it = C.end() - 1;
    while (*it == 0) {
        it = C.erase(it);
        it--;
    }
    if (C.size() == 0) {
        C.push_back(0);
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
        n1.erase(n1.begin());
        isANeg = true;
        aSize--;
    }
    if (n2[0] == '-') {
        n2.erase(n2.begin());
        isBNeg = true;
        bSize--;
    }
    bool AisBig = false;
    if (n1.size() > n2.size()) AisBig = true;
    else if (n1.size() == n2.size() && n1.compare(n2) > 0) AisBig = true;
    vector<int> A;
    for (int i = n1.size() - 1; i >= 0; i--) {
        A.push_back(static_cast<int>(n1[i] - '0'));
    }
    vector<int> B;
    for (int i = n2.size() - 1; i >= 0; i--) {
        B.push_back(static_cast<int>(n2[i] - '0'));
    }

    if (!isANeg && !isBNeg) {
        vector<int> C;
        add(C, A, B);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << '\n';
        if (AisBig) {
            vector<int> D(A);
            sub(D, A, B);
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        else {
            vector<int> D(B);
            sub(D, B, A);
            if (D.size() != 1 || D[0] != 0) {
                cout << '-';
            }
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        if (AisBig) {
            vector<int> E(A.size() * 3, 0);
            multiple(E, A, B);
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
        else {
            vector<int> E(B.size() * 3, 0);
            multiple(E, B, A);
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
    }
    else if (isANeg && !isBNeg) {
        if (AisBig) {
            vector<int> D(A);
            sub(D, A, B);
            cout << '-';
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        else {
            vector<int> D(B);
            sub(D, B, A);
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        vector<int> C;
        add(C, A, B);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << '\n';
        if (AisBig) {
            vector<int> E(A.size() * 3, 0);
            multiple(E, A, B);
            cout << '-';
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
        else {
            vector<int> E(B.size() * 3, 0);
            multiple(E, B, A);
            cout << '-';
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
    }
    else if (!isANeg && isBNeg) {
        if (AisBig) {
            vector<int> D(A);
            sub(D, A, B);
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        else {
            vector<int> D(B);
            sub(D, B, A);
            if (D.size() != 1 || D[0] != 0) {
                cout << '-';
            }
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        vector<int> C;
        add(C, A, B);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << '\n';
        if (AisBig) {
            vector<int> E(A.size() * 3, 0);
            multiple(E, A, B);
            cout << '-';
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
        else {
            vector<int> E(B.size() * 3, 0);
            multiple(E, B, A);
            cout << '-';
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
    }
    else {
        vector<int> C;
        add(C, A, B);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << '\n';
        if (AisBig) {
            vector<int> D(A);
            sub(D, A, B);
            cout << '-';
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        else {
            vector<int> D(B);
            sub(D, B, A);
            for (int i = D.size() - 1; i >= 0; i--) {
                cout << D[i];
            }
            cout << '\n';
        }
        if (AisBig) {
            vector<int> E(A.size() * 3, 0);
            multiple(E, A, B);
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
        else {
            vector<int> E(B.size() * 3, 0);
            multiple(E, B, A);
            for (int i = E.size() - 1; i >= 0; i--) {
                cout << E[i];
            }
        }
    }
}