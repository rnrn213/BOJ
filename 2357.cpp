#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll* treeMax;
ll* treeMin;
ll* nums;

ll initMax(int index, int start, int end) {
	if (start == end) {
		treeMax[index] = nums[start];
	}
	else {
		int mid = (start + end) / 2;
		ll lm = initMax(index * 2 + 1, start, mid);
		ll rm = initMax(index * 2 + 2, mid + 1, end);
		treeMax[index] = (lm > rm) ? lm : rm;
	}
	return treeMax[index];
}

ll initMin(int index, int start, int end) {
	//cout << "initMin(" << index << ", " << start << ", " << end << ") called\n";
	if (start == end) {
		treeMin[index] = nums[start];
	}
	else {
		int mid = (start + end) / 2;
		ll lm = initMin(index * 2 + 1, start, mid);
		ll rm = initMin(index * 2 + 2, mid + 1, end);
		treeMin[index] = (lm > rm) ? rm : lm;
	}
	return treeMin[index];
}

ll getMax(int index, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	else if (start >= left && end <= right) {
		return treeMax[index];
	}
	else {
		int mid = (start + end) / 2;
		ll lm = getMax(index * 2 + 1, start, mid, left, right);
		ll rm = getMax(index * 2 + 2, mid + 1, end, left, right);
		return (lm > rm) ? lm : rm;
	}
}

ll getMin(int index, int start, int end, int left, int right) {
	//cout << "getMin(" << index << ", " << start << ", " << end << ", " << left << ", " << right << ") called\n";
	if (start > right || end < left) return 1000000001;
	else if (start >= left && end <= right) {
		return treeMin[index];
	}
	else {
		int mid = (start + end) / 2;
		ll lm = getMin(index * 2 + 1, start, mid, left, right);
		ll rm = getMin(index * 2 + 2, mid + 1, end, left, right);
		return (lm > rm) ? rm : lm;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	nums = new ll[N];
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int h = ceil(log2(N));
	treeMax = new ll[1<<(h + 1)];
	treeMin = new ll[1<<(h + 1)];
	
	initMax(0, 0, N - 1);
	initMin(0, 0, N - 1);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << getMin(0, 0, N - 1, a - 1, b - 1) << ' ' << getMax(0, 0, N - 1, a - 1, b - 1) << '\n';
	}
}
