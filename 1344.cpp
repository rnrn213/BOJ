#include <bits/stdc++.h>

using namespace std;

const int ROUNDS = 18;
const double E = 10^(-6);

int AB[2];
int prime[] = {2, 3, 5, 7, 11, 13, 17};
vector< vector< vector<double> > > p(2, vector< vector<double> >(ROUNDS + 1, vector<double>(20, 0.0)));


int main() {
    cin >> AB[0] >> AB[1];

    for (int i = 0; i < 2; i++) {
        p[i][0][0] = 1 - (AB[i] / 100.0);
        p[i][0][1] = AB[i] / 100.0;
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < ROUNDS - 1; j++) {
            for (int k = 0; k <= j + 1; k++) {
                p[i][j + 1][k] += p[i][j][k] * (1 - (AB[i] / 100.0));
                p[i][j + 1][k + 1] = p[i][j][k] * (AB[i] / 100.0);
            }
        }
    }

    double ans = 0.0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 7; j++) {
            ans += p[i][ROUNDS - 1][prime[j]];
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            ans -= p[0][ROUNDS - 1][prime[i]] * p[1][ROUNDS - 1][prime[j]];
        }
    }

    cout << ans;
}