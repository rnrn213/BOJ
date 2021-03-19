#include <bits/stdc++.h>

using namespace std;

int N;
double* nums;

double cache[10000];

void input() {
    cin >> N;
    nums = new double[N];
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        nums[i] = num;
    }
}

void initCache() {
    for (int i = 0; i < 10000; i++) {
        cache[i] = -1.0;
    }
}

double solve(int start) {
    if (start == N) return -1;

    
    if (cache[start] != -1.0) return cache[start];
    double ret = nums[start];
    double maxValue = ret;
    for (int i = start + 1; i < N; i++) {
        ret *= nums[i];
        maxValue = max(ret, maxValue);
    }
    cache[start] = maxValue;

    return max(maxValue, solve(start + 1));
}

int main() {
    initCache();
    input();
    printf("%0.3lf", solve(0));
}