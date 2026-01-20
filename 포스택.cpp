#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> s[4];
string ans = "YES";

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		int idx = -1, minTop = 0;
		for (int j = 0; j < 4; j++)
		{
			if (s[j].empty())
			{
				if (minTop == 0) idx = j;
			}
			else
			{
				if (s[j].top() > minTop && s[j].top() < num)
				{
					idx = j;
					minTop = s[j].top();
				}
			}
		}

		if (idx == -1) ans = "NO";
		else
		{
			s[idx].push(num);
		}
	}

	cout << ans;
}