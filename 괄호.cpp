#include <bits/stdc++.h>

using namespace std;

int T, N;
string dmap[1001], s = "";
char brackets[] = {'.', '(', ')', '{', '}', '[', ']'};

int main()
{
    for (int i = 0; i < 3000; i++)
    {
        s += "9";
    }
    for (int i = 0; i < 1001; i++)
    {
        dmap[i] = s;
    }
    dmap[1] = "12"; dmap[2] = "34"; dmap[3] = "56";

    for (int i = 4; i <= 1000; i++)
    {
        string temp;
        for (int j = 1; j < i; j++)
        {
            temp = dmap[j] + dmap[i - j];
            if (temp.size() < dmap[i].size()) dmap[i] = temp;
            else if ((temp.size() == dmap[i].size()) && temp < dmap[i]) dmap[i] = temp;
        }
        if (i % 2 == 0)
        {
            temp = "1" + dmap[i / 2] + "2";
            if (temp.size() < dmap[i].size()) dmap[i] = temp;
            else if ((temp.size() == dmap[i].size()) && temp < dmap[i]) dmap[i] = temp;
        }
        if (i % 3 == 0)
        {
            temp = "3" + dmap[i / 3] + "4";
            if (temp.size() < dmap[i].size()) dmap[i] = temp;
            else if ((temp.size() == dmap[i].size()) && temp < dmap[i]) dmap[i] = temp;
        }
        if (i % 5 == 0)
        {
            temp = "5" + dmap[i / 5] + "6";
            if (temp.size() < dmap[i].size()) dmap[i] = temp;
            else if ((temp.size() == dmap[i].size()) && temp < dmap[i]) dmap[i] = temp;
        }
    }

    cin >> T;
    while (T--)
    {
        cin >> N;

        for (char c : dmap[N])
        {
            cout << brackets[c - '0'];
        }
        cout << "\n";
    }
}