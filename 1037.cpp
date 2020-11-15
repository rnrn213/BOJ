#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, a;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		nums.push_back(num);
	}
	
	sort(nums.begin(), nums.end());
	cout << nums[0] * nums[nums.size() - 1];
}
