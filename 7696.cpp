#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> answer(1000005, 1);
    vector<int> num(1, 1);
    int maxIndex = 0, cnt = 1;
    while (true) {
        num[0]++;
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] != 10) break;
            num[i] = 0;
            num[i + 1]++;
        }
        if (num[maxIndex] == 10) {
            num.push_back(1);
            num[maxIndex] = 0;
            maxIndex++;
        }
        vector<bool> isUsing(10, false);
        for (int i = num.size() - 1; i >= 0; i--) {
            if (isUsing[num[i]]) {
                bool restart = false;
                while (isUsing[num[i]]) {
                    num[i]++;
                    if (num[i] == 10) {
                        restart = true;
                        for (int j = i; j < num.size() - 1; j++) {
                            if (num[j] != 10) break;
                            num[j] = 0;
                            num[j + 1]++;
                        }
                        if (num[maxIndex] == 10) {
                            num.push_back(1);
                            num[maxIndex] = 0;
                            maxIndex++;
                        }
                    }
                    if (restart) break;
                }
                if (restart) {
                    i = num.size();
                    vector<bool> newIsUsing(10, false);
                    isUsing = newIsUsing;
                    continue;
                }
                isUsing[num[i]] = true;
                for (int j = i - 1; j >= 0; j--) {
                    int temp = 0;
                    while (isUsing[temp]) temp++;
                    num[j] = temp;
                    isUsing[temp] = true;
                }
                break;
            }
            else {
                isUsing[num[i]] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            ans += num[i] * pow(10, i);
        }

        cnt++;
        answer[cnt] = ans;
        if (cnt == 1000000) break;
    }
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << answer[n] << "\n";
    }
}