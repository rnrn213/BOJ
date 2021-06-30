#include <bits/stdc++.h>

using namespace std;

vector<int> decToDuodec(int dec) {
    vector<int> duodec;
    while (dec) {
        duodec.push_back(dec % 12);
        dec /= 12;
    }
    return duodec;
    
}

vector<int> decToHex(int dec) {
    vector<int> hex;
    while (dec) {
        hex.push_back(dec % 16);
        dec /= 16;
    }
    return hex;
}

int sumDigits(const vector<int>& num) {
    int sum = 0;
    for (auto n: num) {
        sum += n;
    }
    return sum;
}

int decToInt(const vector<int>& dec) {
    int ret = 0;
    for (int i = 0; i < dec.size(); i++) {
        ret += dec[i] * pow(10, i);
    }
    return ret;
}

void increaseDec(vector<int>& dec) {
    dec[0]++;
    for (int i = 0; i < dec.size() - 1; i++) {
        if (dec[i] == 10) {
            dec[i] = 0;
            dec[i + 1]++;
        }
    }
    if (dec[dec.size() - 1] == 10) {
        dec[dec.size() - 1] = 0;
        dec.push_back(1);
    }
}

void printAns(const vector<int>& ans) {
    for (auto num: ans) {
        cout << num << "\n";
    }
}

int main() {
    vector<int> dec = {0, 0, 0, 1}, ans;
    while (dec.size() == 4) {
        int decInt = decToInt(dec);
        vector<int> duodec = decToDuodec(decInt);
        vector<int> hex = decToHex(decInt);
        if (sumDigits(dec) == sumDigits(duodec) && 
            sumDigits(dec) == sumDigits(hex)) 
            ans.push_back(decInt);
        
        increaseDec(dec);
    }

    printAns(ans);
}