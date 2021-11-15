#include <bits/stdc++.h>

using namespace std;

vector< string > fibo;

string sSum(const string& s1, const string& s2) {
    string ret = "";
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
        if (fibo[i].size() >= 101)
            break;
    }

    while (true) {
        string a, b;
        cin >> a >> b;
        if (a == "0" && b == "0")
            break;

        int cnt = 0;
        for (int i = 0; i < fibo.size(); i++) {
            string temp(fibo[i].rbegin(), fibo[i].rend());
            if ((a.size() < temp.size() || (a.size() == temp.size() && a <= temp)) && 
                (b.size() > temp.size() || (b.size() == temp.size() && temp <= b)))
                cnt++;
        }

        cout << cnt << '\n';
    }
}