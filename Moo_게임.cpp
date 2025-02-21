#include <bits/stdc++.h>

using namespace std;

int N;
char ans = '-';

int S(int k, int num)
{
    if (k == 0)
    {
        if (num == 1) ans = 'm';
        else if (num <= 3) ans = 'o';
        return 3;
    }

    int left = S(k - 1, num);
    if (num > left && num <= left + k + 3)
    {
        int temp = num - left;
        if (temp == 1) ans = 'm';
        else ans = 'o';
    }
    if (num > left + k + 3 && num <= 2 * left + k + 3)
    {
        S(k - 1, num - (left + k + 3));
    }

    return 2 * left + k + 3;
}

int main()
{
    cin >> N;
    int k = 0;
    while (ans == '-')
    {
        S(k++, N);
    }

    cout << ans;
}