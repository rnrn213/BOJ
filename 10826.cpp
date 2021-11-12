#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > cache(10001);

vector<int> vSum(const vector<int>& v1, const vector<int>& v2) {
    vector<int> ret;
    int carry = 0;
    for (int i = 0; i < v2.size(); i++) {
        int num = v1[i] + v2[i];
        ret.push_back((num + carry) % 10);
        carry = (num + carry) / 10;
    }

    if (v1.size() > v2.size()) {
        for (int i = v2.size(); i < v1.size(); i++) {
            ret.push_back((v1[i] + carry) % 10);
            carry = (v1[i] + carry) / 10;
        }
    }

    if (carry > 0)
        ret.push_back(carry);

    return ret;
}

int main() {
    cache[0] = {0};
    cache[1] = {1};

    int n;
    cin >> n;

    if (n < 2)
        cout << n;
    else {
        for (int i = 2; i <= n; i++)
            cache[i] = vSum(cache[i - 1], cache[i - 2]);

        for (int i = cache[n].size() - 1; i >= 0; i--)
            cout << cache[n][i];
    }
}