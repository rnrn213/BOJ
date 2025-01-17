#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end());

    priority_queue<int> pq;
    pq.push(-v[0].second);
    for (int i = 1; i < N; i++)
    {
        if (-pq.top() > v[i].first)
            pq.push(-v[i].second);
    }

    cout << pq.size();

}