#include <bits/stdc++.h>

using namespace std;

int getIndent(const string& s) {
    int indent = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.')
            break;
        indent++;
    }

    return indent;
}

int main() {
    while (true) {
        int p, q;
        cin >> p >> q;
        if (p == 0 && q == 0) break;

        vector<string> P(p), Q(q);
        for (int i = 0; i < p; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> Q[i];
        }

        vector<int> ro(p - 1, 0), rc(p - 1, 0), co(p - 1, 0), cc(p - 1, 0), so(p - 1, 0), sc(p - 1, 0), indent(p - 1, 0);
        for (int i = 0; i < p - 1; i++) {
            for (int j = 0; j < P[i].size(); j++) {
                if (P[i][j] == '(') ro[i]++;
                if (P[i][j] == ')') rc[i]++;
                if (P[i][j] == '{') co[i]++;
                if (P[i][j] == '}') cc[i]++;
                if (P[i][j] == '[') so[i]++;
                if (P[i][j] == ']') sc[i]++;
            }

            if (i > 0) {
                ro[i] += ro[i - 1];
                rc[i] += rc[i - 1];
                co[i] += co[i - 1];
                cc[i] += cc[i - 1];
                so[i] += so[i - 1];
                sc[i] += sc[i - 1];
            }

            indent[i] = getIndent(P[i + 1]);
        }

        vector<int> R, C, S;

        for (int r = 1; r <= 20; r++) {
            for (int c = 1; c <= 20; c++) {
                for (int s = 1; s <= 20; s++) {
                    bool isValid = true;

                    for (int i = 0; i < p - 1; i++) {
                        if (r * (ro[i] - rc[i]) + c * (co[i] - cc[i]) + s * (so[i] - sc[i]) != indent[i]) {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) {
                        R.push_back(r);
                        C.push_back(c);
                        S.push_back(s);
                    }
                }
            }
        }

        int qro = 0, qrc = 0, qco = 0, qcc = 0, qso = 0, qsc = 0;
        cout << 0;
        for (int i = 1; i < q; i++) {
            if (R.size() == 0) {
                cout << " " << -1;
                continue;
            }

            for (int j = 0; j < Q[i - 1].size(); j++) {
                if (Q[i - 1][j] == '(') qro++;
                if (Q[i - 1][j] == ')') qrc++;
                if (Q[i - 1][j] == '{') qco++;
                if (Q[i - 1][j] == '}') qcc++;
                if (Q[i - 1][j] == '[') qso++;
                if (Q[i - 1][j] == ']') qsc++;
            }

            bool isValid = true;
            int indent = R[0] * (qro - qrc) + C[0] * (qco - qcc) + S[0] * (qso - qsc);
            for (int j = 1; j < R.size(); j++) {
                if (R[j] * (qro - qrc) + C[j] * (qco - qcc) + S[j] * (qso - qsc) != indent) {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                cout << " " << indent;
            else
                cout << " " << -1;
        }
        cout << "\n";
    }
}