#include <bits/stdc++.h>

using namespace std;

bool isConvertible(const vector< vector<char> >& source, const vector< vector<char> >& target) {
    for (int i = 0; i < source.size(); i++) {
        for (int j = 0; j < source[i].size(); j++) {
            if (source[i][j] == '#' && target[i][j] != '#') return false;
        }
    }
    return true;
}

string solve(const vector< vector< vector<char> > >& t) {
    vector< vector< vector<char> > > num(10, vector< vector<char> >(5, vector<char>(3)));
    num = {{{'#', '#', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'}}, {{'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}}, {{'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}}, {{'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}}, {{'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}}, {{'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}}, {{'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}}, {{'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}}, {{'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}}, {{'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}}};

    string ret = "";
    for (int i = 0; i < 4; i++) {
        if (i == 2) ret += ":";
        for (int j = 0; j < 10; j++) {
            if (isConvertible(t[i], num[j])) {
                ret += to_string(j);
                break;
            }
        }
    }

    return ret;
}

int main() {
    vector< vector< vector<char> > > t(4, vector< vector<char> >(5, vector<char>(3)));
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < 3; i++) {
                cin >> t[k][j][i];
            }
        }
    }

    cout << solve(t);
}