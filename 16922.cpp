#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<int> v;
    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N; b++) {
            for (int c = 0; c <= N; c++) {
                for (int d = 0; d <= N; d++) {
                    if (a + b + c + d == N)
                        v.push_back(50*a + 10*b + 5*c + d);
                }
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    cout << v.size();
}