#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v(20, 0);

bool solve(int i) {
    if (i == 20) {
        int sum = 0;
        for (auto n: v) {
            sum += n;
        }

        if (sum == N)
            return true;
        else
            return false;
    }

    bool ret = solve(i + 1);
    v[i] = pow(3, i);
    ret = ret || solve(i + 1);
    v[i] = 0;

    return ret;
}

int main() {
    cin >> N;

    if (solve(0) && N != 0)
        cout << "YES";
    else
        cout << "NO";
}