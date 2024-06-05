#include <bits/stdc++.h>

using namespace std;

int G, P, arr[100001];
vector<bool> isValid(100001, true);

int solve(int num)
{
    if (num == 0) return 0;
    if (num == arr[num]) return num;

    return arr[num] = solve(arr[num]);
}

int main()
{
    cin >> G >> P;
    for (int i = 0; i <= G; i++)
    {
        arr[i] = i;
    }
    int cnt = 0;
    bool isDocking = true;
    for (int i = 0; i < P; i++)
    {
        int num;
        cin >> num;

        int gate = solve(num);
        if (gate == 0) isDocking = false;
        if (isDocking)
        {
            cnt++;
            arr[gate] = gate - 1;
        }

    }
    cout << cnt;
}