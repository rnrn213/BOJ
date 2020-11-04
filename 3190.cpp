#include <bits/stdc++.h>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int _x=0, int _y=0) : x(_x), y(_y) {}
	
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

int main() {
	queue<Point*> snake;
	int N, K;
	cin >> N >> K;
	
	bool** visiting = new bool*[N + 2];
	for (int i = 0; i < N + 2; i++) {
		visiting[i] = new bool[N + 2];
		for (int j = 0; j < N + 2; j++) {
			if (i == 1 && j == 1) {
				visiting[i][j] = true;
				snake.push(new Point(i, j));
			}
			else visiting[i][j] = false;
		}
	}
	bool** apple = new bool*[N + 2];
	for (int i = 0; i < N + 2; i++) {
		apple[i] = new bool[N + 2];
		for (int j = 0; j < N + 2; j++) {
			apple[i][j] = false;
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		apple[x][y] = true;
	}
	int L;
	cin >> L;
	queue<pair<int, char>> direction;
	for (int i = 0; i < L; i++) {
		int t;
		char C;
		cin >> t >> C;
		direction.push(make_pair(t, C));
	}
	
	int time = 0;
	int degree = 0;
	int x = 1;
	int y = 1;
	while (true) {
		time++;
		if (degree % 360 == 0) x++;
		else if (degree % 360 == 90 || degree % 360 == -270) y++;
		else if (degree % 360 == 180 || degree % 360 == -180) x--;
		else if (degree % 360 == 270 || degree % 360 == -90) y--;
		
		snake.push(new Point(x, y));
		
		if (x < 1 || x > N || y < 1 || y > N || visiting[x][y] == true) break;
		
		visiting[x][y] = true;
		if (apple[x][y] == false) {
			Point* p = snake.front();
			visiting[p->getX()][p->getY()] = false;
			snake.pop();
			delete p;
		}
		else {
			apple[x][y] = false;
		}
		
		if (time == direction.front().first) {
			if (direction.front().second == 'L') degree -= 90;
			else degree += 90;
			direction.pop();
		}
	}
	cout << time;
}
