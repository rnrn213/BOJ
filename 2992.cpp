#include <bits/stdc++.h>

using namespace std;

string X;

int getMinDiff(string src, string des) {
    if (des.size() == X.size()) {
        int ret = stoi(des) - stoi(X);
        if (ret > 0) return ret;
    }

    int diff = 1000000;
    for (int i = 0; i < src.size(); i++) {
        char temp = src[i];
        src.erase(src.begin() + i);
        diff = min(diff, getMinDiff(src, des + temp));
        src.insert(src.begin() + i, temp);
    }

    return diff;
}

int main() {
    cin >> X;
    int diff = getMinDiff(X, "");
    if (diff == 1000000) cout << 0;
    else cout << stoi(X) + diff;
}