#include <bits/stdc++.h>

using namespace std;

bool binarySearch(const vector<string>& A, string name) {
    int low = 0, high = A.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == name)
            return true;
        
        if (A[mid] < name)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<string> ans;
    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;

        if (binarySearch(A, name))
            ans.push_back(name);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto name: ans) {
        cout << name << "\n";
    }
}