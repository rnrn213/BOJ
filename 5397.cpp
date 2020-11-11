#include <bits/stdc++.h>

using namespace std;

void getPassword(const char* const keylogger, list<char>& password) {
	list<char>::iterator cursor = password.begin();
	int length = strlen(keylogger);
	for (int i = 0; i < length; i++) {
		if (keylogger[i] == '<') {
			if (cursor != password.begin()) cursor--;
		}
		else if (keylogger[i] == '>') {
			if (cursor != password.end()) cursor++;
		}
		else if (keylogger[i] == '-') {
			if (cursor != password.begin()) {
				cursor--;
				cursor = password.erase(cursor);
			}
		}
		else {
			if (cursor == password.end()) {
				password.push_back(keylogger[i]);
				cursor = password.end();
			}
			else {
				cursor = password.insert(cursor, keylogger[i]);
				cursor++;
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		char* keylogger = new char[1000001];
		scanf("%s", keylogger);
		//fgets(keylogger, sizeof(char)*1000001, stdin);
		/*for (int j = 0; j < strlen(keylogger); j++) {
			printf("%c", keylogger[j]);
		}
		printf("\n");*/
		
		list<char> password;
		getPassword(keylogger, password);
		for (list<char>::iterator it = password.begin(); it != password.end(); ++it) {
			printf("%c", *it);
		}
		printf("\n");
	}
}
