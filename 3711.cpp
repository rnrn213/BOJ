#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int G;
    for (int i = 0; i < N; i++) {
        cin >> G;
        vector<int> students(G);
        for (int j = 0; j < G; j++) {
            cin >> students[j];
        }

        int m = 1;
        while (true) {
            vector<int> remain;
            bool isValid = true;
            for (int j = 0; j < G; j++) {
                remain.push_back(students[j] % m);
                if (find(remain.begin(), remain.end(), remain[j]) != remain.end() - 1) {
                    isValid = false;
                    break;
                }
            }
            if (isValid && remain.size() == G) break;
            m++;
        }
        cout << m << "\n";
    }
}