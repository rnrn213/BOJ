#include <bits/stdc++.h>

using namespace std;

int N, A[50], S;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> S;
}

void swap(int i, int j) {
    while (j > i + 1) {
        int temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;

        j--;
    }
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;

    return;
}

void solve(int idx) {
    if (S == 0 || idx == N)
        return;
    
    int idxRange = (idx + S <= N - 1) ? idx + S : N - 1;

    int maxValueIdx = idx;
    for (int i = idx + 1; i <= idxRange; i++) {
        if (A[i] > A[maxValueIdx])
            maxValueIdx = i;
    }

    if (maxValueIdx != idx) {
        S -= maxValueIdx - idx;
        swap(idx, maxValueIdx);
    }

    solve(idx + 1);
}

void output() {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    input();
    solve(0);
    output();
}