#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    
    vector<string> cheese;
    bool isAns = false;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s.size() < 6) continue;
        if (s.substr(s.size() - 6) == "Cheese")
        {
            bool isValid = true;
            for (int j = 0; j < cheese.size(); j++)
            {
                if (cheese[j] == s)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
                cheese.push_back(s);
        }
    }

    if (cheese.size() >= 4) cout << "yummy";
    else cout << "sad";
}