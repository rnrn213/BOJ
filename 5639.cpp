#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int sz;

void f(int start, int end) {
    if (start == end) {
        cout << v[start] << "\n";
        return;
    }
    if (start > end) return;

    int root = v[start];

    int mid = start + 1;
    while (mid <= end) {
        if (v[mid] > root) break;
        mid++;
    }

    f(start + 1, mid - 1);
    f(mid, end);

    cout << root << "\n";
}

int main() {
    int key;
    while (cin >> key) {
        v.push_back(key);
    }
    sz = v.size();

    f(0, sz - 1);
}