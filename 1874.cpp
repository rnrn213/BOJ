#include <bits/stdc++.h>

using namespace std;

vector<char> answer;

class myStack {
private:
    vector<int> s;
public:
    myStack(): s() {}

    void push(int X) {
        s.push_back(X);
        //cout << "push " << X << '\n';
        answer.push_back('+');
    }
    int pop() {
        if (s.size() == 0) return -1;
        else {
            int temp = s[s.size() - 1];
            s.erase(s.end() - 1);
            //cout << "pop " << temp << '\n';
            answer.push_back('-');
            return temp;
        }
    }
    int size() {
        return s.size();
    }
    int top() {
        if (s.size() == 0) return -1;
        else return s[s.size() - 1];
    }
};

int main() {
	int n, num, a = 1;
	cin >> n;
	
	myStack s;
	s.push(a);
	a++;
	//answer.push_back('+');
	
	bool isValid = true;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num < s.top()) {
			isValid = false;
			break;
		}
		if (num == s.top()) {
			s.pop();
			//answer.push_back('-');
		}
		else if (num > s.top()) {
			while(num > s.top()) {
				s.push(a);
				a++;
				//answer.push_back('+');
			}
			s.pop();
			//answer.push_back('+');
		}
	}
	
	if (!isValid) cout << "NO";
	else {
		for (int i = 0; i < answer.size() - 1; i++) {
			cout << answer[i] << '\n';
		}
		cout << answer[answer.size() - 1];
	}
}
