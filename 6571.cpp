#include <bits/stdc++.h>

using namespace std;

vector< string > fibo;

string sSum(const string& s1, const string& s2) {
    string ret;
    int carry = 0;
    for (int i = 0; i < s2.size(); i++) {
        int num = s1[i] - '0' + s2[i] - '0';
        ret += to_string((num + carry) % 10);
        carry = (num + carry) / 10;
    }

    if (s1.size() > s2.size()) {
        for (int i = s2.size(); i < s1.size(); i++) {
            ret += to_string((s1[i] - '0' + carry) % 10);
            carry = (s1[i] - '0' + carry) / 10;
        }
    }

    if (carry > 0)
        ret += to_string(carry);

    return ret;
}

int main() {
    fibo.push_back("1");
    fibo.push_back("2");
    for (int i = 2;; i++) {
        fibo.push_back(sSum(fibo[i - 1], fibo[i - 2]));
        if (fibo[i].size() >= 100)
            break;
    }

    while (true) {
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << a << " " << b << "\n";
        if (a == "0" && b == "0")
            break;

        int i = -1, j = -1, idx1 = 0, idx2 = fibo.size() - 1;
        while (idx1 < fibo.size() && idx2 >= 0) {
            if (i == -1 && (a.size() < fibo[idx1].size() || (a.size() == fibo[idx1].size() && a <= fibo[idx1])))
                i = idx1;
            if (j == -1 && (b.size() > fibo[idx2].size() || (b.size() == fibo[idx2].size() && b >= fibo[idx2])))
                j = idx2;
            
            idx1++;
            idx2--;
        }

        cout << j - i + 1 << "\n";
    }
}