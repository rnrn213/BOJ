#include <bits/stdc++.h>

using namespace std;

vector<string> day = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int timetoint(const string& s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string inttotime(const int t) {
    string s = "";
    if (t / 60 < 10)
        s += "0";
    s += to_string(t / 60) + ":";
    if (t % 60 < 10)
        s += "0";
    s += to_string(t % 60);

    return s;
}

int main() {
    int star1Start, star2Start, star1Interval, star2Interval;
    string t;
    cin >> t;
    star1Start = timetoint(t);
    cin >> t;
    star2Start = timetoint(t);
    cin >> t;
    star1Interval = timetoint(t);
    cin >> t;
    star2Interval = timetoint(t);

    int star1 = star1Start, star2 = star2Start, star1limit, star2limit, cnt = 0;
    bool star1finish = false, star2finish = false;
    string ans = "";

    for (int j = 0; j <= 1440; j++) {
        for (int i = 0; i <= 1440; i++) {
            if (star1Interval * i - star2Interval * j == star2Start - star1Start && ans == "") {
                ans = day[((star1Start + star1Interval * i) % 10080) / 1440] + "\n" + inttotime(((star1Start + star1Interval * i) % 10080) % 1440);
            }
        }
    }

    if (ans == "") cout << "Never";
    else cout << ans;
}