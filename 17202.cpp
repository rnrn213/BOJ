#include <bits/stdc++.h>

using namespace std;

string solve(string& AB) {
    int ABSize = AB.size();

    if (ABSize == 2)
        return AB;

    string nextAB = "";
    for (int i = 0; i < ABSize - 1; i++)
        nextAB += to_string((AB[i] - '0' + AB[i + 1] - '0') % 10);

    return solve(nextAB);
}

int main() {
    string A, B;
    cin >> A >> B;
    
    string AB = "";
    int i = 0;
    while (i < A.size()) {
        AB += A[i];
        AB += B[i++];
    }

    cout << solve(AB);
}