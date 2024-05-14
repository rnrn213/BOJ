#include <bits/stdc++.h>

using namespace std;

int N;
long long B;
vector< vector<int> > A(5, vector<int>(5));

vector< vector<int> > mm(const vector< vector<int> >& a, const vector< vector<int> >& b)
{
    vector< vector<int> > ret(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % 1000;
            }
        }
    }
    return ret;
}

vector< vector<int> > solve(long long B)
{
    if (B == 0)
    {
        vector< vector<int> > ret(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            ret[i][i] = 1;
        }
        return ret;
    }
    if (B % 2 == 1)
    {
        return mm(A, solve(B - 1));

    }
    vector< vector<int> > temp = solve(B / 2);
    return mm(temp, temp);
}

int main()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    vector< vector<int> > ans = solve(B);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}