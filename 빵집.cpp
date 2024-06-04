// 질문 게시판 참고 https://www.acmicpc.net/board/view/121413
#include <bits/stdc++.h>

using namespace std;

int R, C;
string arr[10002];
bool cc[10002][500], isVisited[10002][500];

bool solve(int y, int x)
{
    if (arr[y][x] != '.') return false;
    if (x == C - 1) return true;

    arr[y][x] = 'x';

    return solve(y - 1, x + 1) || solve(y, x + 1) || solve(y + 1, x + 1);
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i <= R + 1; i++)
    {
        if (i == 0 || i == R + 1)
        {
            arr[i] = "";
            for (int j = 0; j < C; j++)
            {
                arr[i] += "x";
            }
        }
        else
        {
            cin >> arr[i];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= R; i++)
    {
        if (solve(i, 0)) cnt++;
    }
    cout << cnt;
}