#include <bits/stdc++.h>

using namespace std;

vector< vector< vector<int> > > cache(101, vector< vector<int> >(101, vector<int>()));

vector<int> vSum(const vector<int>& v1, const vector<int>& v2) {
    if (v1.size() < v2.size())
        return vSum(v2, v1);

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

vector<int> solve(int n, int m) {
    vector<int>& ret = cache[n][m];
    if (ret.size() != 0)
        return ret;

    if (n == m || m == 0)
        return ret = {1};
    

    vector<int> v1 = solve(n - 1, m - 1), v2 = solve(n - 1, m);
    return ret = vSum(v1, v2);
}

int main() {
    int n, m;
    cin >> n >> m;

    solve(n, m);

    for (int i = cache[n][m].size() - 1; i >= 0; i--) {
        cout << cache[n][m][i];
    }
}