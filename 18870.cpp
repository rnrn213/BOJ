#include <bits/stdc++.h>

using namespace std;

int binarySearch(const vector<int>& sortedX, int num) {
    int low = 0, high = sortedX.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (sortedX[mid] == num)
            return mid;
        
        if (sortedX[mid] > num)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    vector<int> sortedX = X;
    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());

    for (int i = 0; i < N; i++) {
        X[i] = binarySearch(sortedX, X[i]);
    }

    for (auto num: X) {
        cout << num << " ";
    }
}