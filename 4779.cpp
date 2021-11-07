#include <bits/stdc++.h>

using namespace std;

string s;

string solve(int pos, int N) {
    if (N == 0) {
        if (pos == 1)
            return " ";
        else
            return "-";
    }
    if (pos == 1) {
        string ret = "";
        int retSize = pow(3, N);
        for (int i = 0; i < retSize; i++)
            ret += " ";
        return ret;
    }
    
    return solve(0, N - 1) + solve(1, N - 1) + solve(2, N - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while (cin >> N) {
        s = "";
        int sSize = pow(3, N);
        for (int i = 0; i < sSize; i++)
            s += "-";

        cout << solve(0, N) << "\n";
    }
}