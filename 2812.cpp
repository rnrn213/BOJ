#include <bits/stdc++.h>

using namespace std;

int N, K;
string num;

int main()
{
    cin >> N >> K >> num;

    deque<int> dq;
    for (int i = 0; i < N; i++)
    {
        while (!dq.empty() && K > 0 && num[i] - '0' > dq.back())
        {
            dq.pop_back();
            K--;
        }
        dq.push_back(num[i] - '0');
    }

    while (!dq.empty())
    {
        cout << dq.front();
        dq.pop_front();
    }
}