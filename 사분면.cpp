#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int d;
ll bx, by;
string n, ans = "";

int main()
{
    ll ansx, ansy;
    cin >> d >> n >> ansx >> ansy;

    for (int i = 0; i < d; i++)
    {
        bx *= 2; by *= 2;
        if (n[i] == '1')
        {
            bx += 1;
            by += 1;
        }
        if (n[i] == '2')
        {
            by += 1;
        }
        if (n[i] == '3')
        {

        }
        if (n[i] == '4')
        {
            bx += 1;
        }
    }
    bx += ansx; by += ansy;

    if (bx < 0 || by < 0 || bx >= pow(2, d) || by >= pow(2, d))
    {
        cout << -1;
    }
    else
    {
        for (int i = d - 1; i >= 0; i--)
        {
            if (bx >= pow(2, i))
            {
                if (by >= pow(2, i)) 
                {
                    ans += "1";
                    by -= pow(2, i);
                }
                else ans += "4";

                bx -= pow(2, i);
            }
            else
            {
                if (by >= pow(2, i)) 
                {
                    ans += "2";
                    by -= pow(2, i);
                }
                else ans += "3";
            }
        }

        cout << ans;
    }
}