#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> negFibo, posFibo;

void input() {
    cin >> n;
}

void getNegFibo() {
    negFibo.push_back(0);
    negFibo.push_back(1);
    negFibo.push_back(-1);
    
    for (int i = 3; i <= 1000000; i++) 
        negFibo.push_back((negFibo[i - 2] - negFibo[i - 1]) % 1000000000);
}

void getPosFibo() {
    posFibo.push_back(0);
    posFibo.push_back(1);

    for (int i = 2; i <= 1000000; i++) 
        posFibo.push_back((posFibo[i - 1] + posFibo[i - 2]) % 1000000000);
}

void output() {
    if (n < 0) {
        if (negFibo[-n] < 0) cout << "-1\n" << abs(negFibo[-n]);
        else cout << "1\n" << negFibo[-n];
    }
    else if (n == 0)
        cout << "0\n" << posFibo[n];
    else 
        cout << "1\n" << posFibo[n];
}

int main() {
    input();
    getNegFibo();
    getPosFibo();
    output();
}