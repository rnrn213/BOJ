#include <bits/stdc++.h>

using namespace std;

/*
void quickSort(vector<int>& v, int start, int end) {
    if (start >= end)
        return;
    
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    
    while (i <= j) {
        while (i <= end && v[i] <= v[pivot])
            i++;
        while (j > start && v[j] >= v[pivot])
            j--;
        
        if (i > j) {
            int temp = v[j];
            v[j] = v[pivot];
            v[pivot] = temp;
        }
        else {
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    
    quickSort(v, start, j - 1);
    quickSort(v, j + 1, end);
}
*/

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (auto n: v) {
        cout << n << "\n";
    }
}