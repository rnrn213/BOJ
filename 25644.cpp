#include <bits/stdc++.h>

using namespace std;

int N, a[200000];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int minSP = a[0], maxPrice = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] - minSP > maxPrice)
        {
            maxPrice = a[i] - minSP;
        }
        if (a[i] < minSP)
        {
            minSP = a[i];
        }
    }

    cout << maxPrice;
}