#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int firstMinA, secondMinA, thirdMinA = 10001, fourthMinA = 10002;
    cin >> firstMinA >> secondMinA;
    if (firstMinA > secondMinA) {
        int temp = firstMinA;
        firstMinA = secondMinA;
        secondMinA = temp;
    }

    
    for (int i = 3; i <= n; i++) {
        int num;
        cin >> num;

        if (num < firstMinA) {
            int temp = firstMinA;
            firstMinA = num;
            fourthMinA = thirdMinA;
            thirdMinA = secondMinA;
            secondMinA = temp;
        }
        else if (num < secondMinA && num != firstMinA) {
            int temp = secondMinA;
            secondMinA = num;
            fourthMinA = thirdMinA;
            thirdMinA = temp;
        }
        else if (num < thirdMinA && num != firstMinA && num != secondMinA) {
            fourthMinA = thirdMinA;
            thirdMinA = num;
        }
        else if (num < fourthMinA && num != firstMinA && num != secondMinA && num != thirdMinA) {
            fourthMinA = num;
        }
    }

    vector<int> v;
    v.push_back(stoi(to_string(firstMinA) + to_string(secondMinA)));
    v.push_back(stoi(to_string(secondMinA) + to_string(firstMinA)));
    v.push_back(stoi(to_string(firstMinA) + to_string(thirdMinA)));
    v.push_back(stoi(to_string(thirdMinA) + to_string(firstMinA)));
    v.push_back(stoi(to_string(secondMinA) + to_string(thirdMinA)));
    v.push_back(stoi(to_string(thirdMinA) + to_string(secondMinA)));
    v.push_back(stoi(to_string(firstMinA) + to_string(fourthMinA)));
    sort(v.begin(), v.end());

    cout << v[2] << "\n";
}