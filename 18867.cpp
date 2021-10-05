#include <bits/stdc++.h>

using namespace std;

string ans;
vector<int> v;
bool isFinished = false;

long long s(int x, int index = 814) {
    if (index <= 4) {
        return ((static_cast<long long>(pow(x, index / 2)) % 20200429) * (static_cast<long long>(pow(x, index / 2 + index % 2)) % 20200429)) % 20200429;
    }

    return (s(x, index / 2) * s(x, index / 2 + index % 2)) % 20200429;
}

void getY(int y, int size) {
    if (y == 20200402) {
        cout << "success";
        return;
    }
    if (size > 990316) {
        cout << y << "\n";
        return;
    }
        

    for (int i = 0; i < 62; i++) {
        getY((y +v[i]) % 20200429, size + 1);
    }
}

void solve() {

    for (int i = 48; i <= 57; i++) {
        v.push_back(s(i));
    }

    for (int i = 65; i <= 90; i++) {
        v.push_back(s(i));
    }

    for (int i = 97; i <= 122; i++) {
        v.push_back(s(i));
    }
    
    int y = 0;

    while (y != 20200402) {
        
    }

    getY(0, 0);
}

int main() {
    solve();


}