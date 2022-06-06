#include <bits/stdc++.h>

using namespace std;

string binarySearch(const vector< pair<string, string> >& sites, const string& siteAddress) {
    int low = 0, high = sites.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (sites[mid].first == siteAddress)
            return sites[mid].second;
        
        if (sites[mid].first < siteAddress)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return "null";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector< pair<string, string> > sites(N);
    for (int i = 0; i < N; i++) {
        cin >> sites[i].first >> sites[i].second;
    }

    sort(sites.begin(), sites.end());

    for (int i = 0; i < M; i++) {
        string siteAddress;
        cin >> siteAddress;

        cout << binarySearch(sites, siteAddress) << "\n";
    }
}