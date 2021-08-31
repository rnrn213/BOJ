#include <bits/stdc++.h>

using namespace std;

bool isValid(const string& w, const string& m) {
    int prev = 0;
    for (int i = 0; i < m.size(); i++) {
        if (w.find(m[i], prev) == string::npos) return false;

        prev = w.find(m[i], prev) + 1;
    }

    return true;
}

int main() {
    string m;
    cin >> m;
    int N;
    cin >> N;
    double maxGBS = 0.0;
    string ans = "";
    for (int i = 0; i < N; i++) {
        string w;
        int g;
        cin >> w >> g;

        if (isValid(w, m)) {
            int diff = w.size() - m.size();
            double gbs = static_cast<double>(g) / diff;
            if (gbs - maxGBS > numeric_limits<double>::epsilon()) {
                maxGBS = gbs;
                ans = w;
            }
        }
    }

    if (ans == "") cout << "No Jam";
    else cout << ans;
}