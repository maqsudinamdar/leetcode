/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 

int helper(int d, vector<int>& a) {
    int n = a.size();
    set<int> chosen;

    int curr = 0;
    while (curr + d < a[n - 1]) {
        auto it = upper_bound(a.begin(), a.end(), curr + d);
        it--;
        if (*it == curr) return false;      // frog cannot move and still at same pos
        curr = *it;
        chosen.insert(curr);
    }

    vector<int> left;
    for (int i = 0; i < n; i++) {
        if (chosen.count(a[i]) > 0) {
            continue;
        } else {
            left.push_back(a[i]);       // left stones
        }
    }

    for (int i = 1; i < left.size(); i++) {
        if (left[i] - left[i - 1] > d) return false;
    }

    return true;
}

int maxJump(vector<int>& stones) {
    int n = stones.size();
    int l = 0, r = stones[n - 1], mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (helper(mid, stones)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;

}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxJump(a) << endl;
    }
    return 0;
}