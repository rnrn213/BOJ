#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    
    vector<long long> v;
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);
    for (int i = 3; i <= 1000; i++) {
        v.push_back((v[i - 1] + v[i - 2]) % 10007);
    }

    int n;
    cin >> n;
    cout << v[n];
}