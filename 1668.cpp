#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> trophy(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> trophy[i];
    }

    int countLeft = 0, countRight = 0, maxValueLeft = 0, maxValueRight = 0, 
        i = 0, L = 0, R = trophy.size() - 1;
    while (i < trophy.size()) {
        if (trophy[L] > maxValueLeft) {
            maxValueLeft = trophy[L];
            countLeft++;
        }
        if (trophy[R] > maxValueRight) {
            maxValueRight = trophy[R];
            countRight++;
        }
        L++;
        R--;
        i++;
    }
    cout << countLeft << "\n" << countRight;
}