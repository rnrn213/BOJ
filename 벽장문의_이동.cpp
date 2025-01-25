#include <bits/stdc++.h>

using namespace std;

int N, cache[1 << 20][20], arr[20], length;

int solve(int mask, int idx)
{
    if (idx == length)
        return 0;

    int& ret = cache[mask][idx];
    if (ret != -1) return ret;
    ret = 100000000;

    int temp = mask, pos = arr[idx], cnt = 0;
    while (pos > 0 && (temp & (1 << (pos - 1))))
    {
        pos--;
        cnt++;
    }
    if (pos > 0)
    {
        temp ^= 1 << (arr[idx] - 1);
        temp ^= 1 << (pos - 1);
        ret = cnt + solve(temp, idx + 1);
    }
    temp = mask, pos = arr[idx], cnt = 0;
    while (pos <= N && (temp & (1 << (pos - 1))))
    {
        pos++;
        cnt++;
    }
    if (pos <= N)
    {
        temp ^= 1 << (arr[idx] - 1);
        temp ^= 1 << (pos - 1);
        ret = min(ret, cnt + solve(temp, idx + 1));
    }

    //bitset<8> x(mask);
    //cout << x << " " << idx << " " << ret << "\n";

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N;
    int a, b, mask = (1 << N) - 1;
    cin >> a >> b;
    mask &= ~(1 << (a - 1));
    mask &= ~(1 << (b - 1));
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    cout << solve(mask, 0);
}