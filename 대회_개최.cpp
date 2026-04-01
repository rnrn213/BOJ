#include <bits/stdc++.h>

using namespace std;

int E, EM, M, MH, H;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> E >> EM >> M >> MH >> H;
    }

    int cnt = 0;
    while (true)
    {
        if (E == 0)
        {
            if (EM == 0) break;
            else EM--;
        }
        else E--;
        if (M == 0)
        {
            if (EM == 0 && MH == 0) break;

            if (EM == 0) MH--;
            else if (MH == 0) EM--;
            else
            {
                if (E + EM >= MH + H) EM--;
                else MH--;
            }
        }
        else M--;
        if (H == 0)
        {
            if (MH == 0) break;
            else MH--;
        }
        else H--;

        cnt++;
    }

    cout << cnt;
}