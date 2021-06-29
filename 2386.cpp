#include <bits/stdc++.h>

using namespace std;



int main() {
    while (true) {
        char* s = new char[255];
        cin.getline(s, 255);
        if (s[0] == '#') break;

        int count = 0;
        for (int i = 2; i < 255; i++) {
            if (s[i] == '\0') break;
            if (s[i] == s[0] || s[i] == s[0] - 32) count++;
        }

        cout << s[0] << " " << count << "\n";
        delete [] s;
    }
}