#include <bits/stdc++.h>

using namespace std;

bool isInA(const vector<int>& A, int num) {
    int start = 0, end = A.size() - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (A[mid] == num)
            return true;
        else if (A[mid] < num) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        if (isInA(A, num))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}