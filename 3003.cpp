#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    vector<int> C = {1, 1, 2, 2, 2, 8};
    vector<int> A(6, 0);
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4] >> A[5];

    for (int i = 0; i < A.size(); i++) {
        cout << C[i] - A[i] << ' ';
    }
}