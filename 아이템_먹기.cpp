#include <bits/stdc++.h>

using namespace std;

int N, M, A, B, board[101][101], cache[101][101], cnt;
vector<pair<int, int>> v;

int solve(int y, int x)
{
    if (cnt < A && (y > v[cnt].first || x > v[cnt].second)) return 0;
    if (y == N && x == M) return 1;

    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;

    if (y < N && board[y + 1][x] != 2)
    {
        if (board[y + 1][x] == 1)
        {
            cnt++;
            ret += solve(y + 1, x);
            cnt--;
        }
        else
        {
            ret += solve(y + 1, x);
        }
    }
    if (x < M && board[y][x + 1] != 2)
    {
        if (board[y][x + 1] == 1)
        {
            cnt++;
            ret += solve(y, x + 1);
            cnt--;
        }
        else
        {
            ret += solve(y, x + 1);
        }
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> A >> B;
    for (int i = 0; i < A; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
        v.push_back(make_pair(y, x));
    }
    for (int i = 0; i < B; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y][x] = 2;
    }

    sort(v.begin(), v.end());

    if (board[1][1] == 1) cnt++;
    cout << solve(1, 1);
}