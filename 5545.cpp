#include <bits/stdc++.h>

using namespace std;

int N, A, B, C, D[100];

int main()
{
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }

    sort(D, D + N, greater<>());

    int kcal = C, price = A, i = 0;
    double kpp = (double)kcal / price;
    for (int i = 0; i < N; i++)
    {
        if ((double)(kcal + D[i]) / (price + B) - kpp < 0) break;

        kcal += D[i];
        price += B;
        kpp = (double)kcal / price;
    }

    cout << (int)kpp;
}