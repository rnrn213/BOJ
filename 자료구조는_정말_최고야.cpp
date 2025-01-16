#include <bits/stdc++.h>

using namespace std;

int N, M, arr[200001];
stack<int> s[200000];

int main()
{
    memset(arr, -1, sizeof(arr));

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int num;
            cin >> num;
            s[i].push(num);
        }

        arr[s[i].top()] = i;
        cout << "arr[" << s[i].top() << "] = " << i << "\n";
    }

    int num = 1;
    while (arr[num] != -1 && num <= N)
    {
        s[arr[num]].pop();
        if (!s[arr[num]].empty())
            arr[s[arr[num]].top()] = arr[num];
        num++;
    }

    if (num == N + 1) cout << "Yes";
    else cout << "No";
}