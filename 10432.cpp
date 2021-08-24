#include <bits/stdc++.h>

using namespace std;

int main() {
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int T;
        cin >> T;
        vector<int> progression(12);
        for (int j = 0; j < 12; j++) {
            cin >> progression[j];
        }

        int count = 0;
        for (int j = 1; j <= 10; j++) {
            if (progression[j] > progression[j - 1]) {
                int minNum = progression[j];
                for (int k = j + 1; k <= 11; k++) {
                    if (minNum > progression[k] && minNum > progression[j - 1]) {
                        count++;                    
                    }
                    minNum = min(minNum, progression[k]);
                }
            }
        }

        cout << T << " " << count << "\n";
    }
}