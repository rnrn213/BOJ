#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<string> clothesTypes;
        for (int j = 0; j < n; j++) {
            string clothesName, clothesType;
            cin >> clothesName >> clothesType;

            clothesTypes.push_back(clothesType);
        }
        sort(clothesTypes.begin(), clothesTypes.end());

        int ans = 1, index = 0;
        while (index < n) {
            int cnt = 0, j = 0;
            string clothesType = clothesTypes[index];
            while (index + j < n && clothesTypes[index + j] == clothesType) {
                cnt++;
                j++;
            }
            
            index += j;
            ans = ans * (cnt + 1);
        }

        cout << ans - 1 << "\n";
    }
}