#include <bits/stdc++.h>

using namespace std;

int main() {
    int price;
    cin >> price;

    int change = 1000 - price, count = 0;
    while (change) {
        if (change >= 500)
            change -= 500;
        else if (change >= 100)
            change -= 100;
        else if (change >= 50)
            change -= 50;
        else if (change >= 10)
            change -= 10;
        else if (change >= 5)
            change -= 5;
        else
            change -= 1;
        
        count++;
    }

    cout << count;
}