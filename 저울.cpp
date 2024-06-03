#include <bits/stdc++.h>

using namespace std;

int N, arr[1000];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int sum = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > sum) break;
        sum += arr[i];
    }

    cout << sum + 1;
}