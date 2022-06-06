#include <bits/stdc++.h>

using namespace std;

vector<bool> S(21, false);

void add(int x) {
    S[x] = true;
}

void remove(int x) {
    S[x] = false;
}

int check(int x) {
    if (S[x])
        return 1;
    else
        return 0;
}

void toggle(int x) {
    S[x] = !S[x];
}

void all() {
    for (int i = 1; i <= 20; i++) {
        S[i] = true;
    }
}

void empty() {
    for (int i = 1; i <= 20; i++) {
        S[i] = false;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string operation;
        int x;
        cin >> operation;
        if (operation != "all" && operation != "empty") {
            cin >> x;

            if (operation == "add")
                add(x);
            if (operation == "remove")
                remove(x);
            if (operation == "check")
                cout << check(x) << "\n";
            if (operation == "toggle")
                toggle(x);
        }
        else {
            if (operation == "all")
                all();
            if (operation == "empty")
                empty();
        }
    }
}