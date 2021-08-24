#include <bits/stdc++.h>

using namespace std;

vector<int> inputProgression(int& size) {
    cin >> size;
    vector<int> ret(size);
    for (int i = 0; i < size; i++) {
        cin >> ret[i];
    }

    return ret;
}

bool isLuckyNumber(int num) {
    while (num) {
        if (num % 10 != 5 && num % 10 != 8) return false;
        num /= 10;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M, K;
        vector<int> A = inputProgression(N);
        vector<int> B = inputProgression(M);
        vector<int> C = inputProgression(K);

        vector<int> ans;
        for (int AIndex = 0; AIndex < N; AIndex++) {
            for (int BIndex = 0; BIndex < M; BIndex++) {
                for (int CIndex = 0; CIndex < K; CIndex++) {
                    if (isLuckyNumber(A[AIndex] + B[BIndex] + C[CIndex]))
                        ans.push_back(A[AIndex] + B[BIndex] + C[CIndex]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size() << "\n";
    }
}