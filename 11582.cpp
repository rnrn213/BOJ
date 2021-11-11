#include <bits/stdc++.h>

using namespace std;

int N, k;
vector<int> chickens;

void merge(int left, int right) {
    vector<int> temp(right - left + 1);

    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = 0;
    while (i <= mid || j <= right) {
        if (i <= mid && (j == right + 1 || chickens[i] <= chickens[j])) {
            temp[k++] = chickens[i++];
        }
        else {
            temp[k++] = chickens[j++];
        }
    }

    for (int idx = left; idx <= right; idx++) {
        chickens[idx] = temp[idx - left];
    }
}

void solve(int left, int right, int n) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    solve(left, mid, n / 2);
    solve(mid + 1, right, n / 2);
    if (N / n >= k)
        merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    chickens = vector<int>(N);
    for (int i = 0; i < N; i++) 
        cin >> chickens[i];
    cin >> k;

    solve(0, N - 1, N);

    for (auto c: chickens)
        cout << c << " ";
}