/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int ternarySearch(int ele, vector<int>& heaters) {
    int l = 0, r = heaters.size() - 1;

    while (r - l > 3) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        int diff1 = abs(heaters[mid1] - ele);
        int diff2 = abs(heaters[mid2] - ele);

        if (diff1 < diff2) {
            r = mid2 - 1;
        } else {
            l = mid1 + 1;
        }
    }

    // bruteforce remaining l..r
    int mini = INT_MAX;
    for (int i = l; i <= r; i++) {
        mini = min(mini, abs(heaters[i] - ele));
    }   
    return mini;
}
 
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int maxi = INT_MIN;
    for (int i = 0; i < houses.size(); i++) {
        int x = ternarySearch(houses[i], heaters);
        maxi = max(maxi, x);
    }
    return maxi;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        int m; cin >> m; vector<int> houses(m); for (int i = 0; i < m; i++) cin >> houses[i];
        int n; cin >> n; vector<int> heaters(n); for (int i = 0; i < n; i++) cin >> heaters[i];
        
        cout << findRadius(houses, heaters) << endl;
    }
    return 0;
}