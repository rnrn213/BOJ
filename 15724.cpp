#include <bits/stdc++.h>

using namespace std;

int N, M, p[1025][1025], partialSum[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> p[i][j];
            
            partialSum[i][j] = p[i][j] + partialSum[i][j - 1];
        }
    }
    for (int j = 1; j <= M; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            partialSum[i][j] += partialSum[i - 1][j];
        }
    }

    int K, x1, y1, x2, y2;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << partialSum[x2][y2] - partialSum[x2][y1 - 1] - partialSum[x1 - 1][y2] + partialSum[x1 - 1][y1 - 1] << '\n';
    }
}