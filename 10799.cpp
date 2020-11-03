#include <bits/stdc++.h>

using namespace std;

class myStack {
private:
    vector<int> s;
public:
    myStack(): s() {}

    void push(int X) {
        s.push_back(X);
    }
    int pop() {
        if (s.size() == 0) return -1;
        else {
            int temp = s[s.size() - 1];
            s.erase(s.end() - 1);
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
	myStack s;
	
	string pipe;
	cin >> pipe;
	int numberOfPipe = 0, answer = 0;
	for (int i = 0; i < pipe.length(); i++) {
		if (pipe[i] == '(') {
			numberOfPipe++;
			
			s.push(1);
		}
		else if (pipe[i] == ')') {
			if (s.top() == 1) {
				numberOfPipe--;
				answer += numberOfPipe;
			}
			else if (s.top() == 2) {
				answer++;
				numberOfPipe--;
			}
			
			s.push(2);
		}
	}
	cout << answer;
}
