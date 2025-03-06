#include <bits/stdc++.h>

using namespace std;

long long N;
int P, Q, X, Y;
map<long long, long long> cache;

long long solve(long long num)
{
    if (num <= 0) return 1;

    auto iter = cache.find(num);
    if (iter != cache.end()) return iter->second;
    
    long long ret = solve(num / P - X) + solve(num / Q - Y);
    cache.insert({num, ret});

    return ret;
}

int main()
{
    cin >> N >> P >> Q >> X >> Y;

    cout << solve(N);
}