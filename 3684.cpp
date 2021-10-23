#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> inputData, outputData;

vector<int> getOutputData(int a, int b) {
    vector<int> outputData;
    for (int i = 0; i < T - 1; i++) {
        int x = (a * inputData[i] + b) % 10001;
        if ((a * x + b) % 10001 != inputData[i + 1])
            break;
        outputData.push_back(x);
    }
    outputData.push_back((a * inputData[T - 1] + b) % 10001);

    return outputData;
}

void solve() {
    for (int a = 0; a <= 10000; a++) {
        for (int b = 0; b <= 10000; b++) {
            int x2 = (a * inputData[0] + b) % 10001;
            if (T > 1 && (a * x2 + b) % 10001 == inputData[1])
                outputData = getOutputData(a, b);
            if (outputData.size() == T)
                return;
        }
    }
}

int main() {
    cin >> T;
    inputData = vector<int>(T);
    for (int i = 0; i < T; i++) {
        cin >>  inputData[i];
    }

    solve();

    for (auto d: outputData) {
        cout << d << "\n";
    }
}