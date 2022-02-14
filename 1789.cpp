#include <bits/stdc++.h>

using namespace std;

int main() {
    long long S;
    cin >> S;

    long long i = 1;
    while (S - (i * (i + 1)) / 2 > i)
        i++;
    
    cout << i;
}