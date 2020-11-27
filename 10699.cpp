#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    time_t t;
    struct tm* seoulTime;

    t = time(NULL);
    seoulTime = localtime(&t);

    cout << seoulTime->tm_year + 1900 << "-" << seoulTime->tm_mon + 1 << "-" << seoulTime->tm_mday;
}