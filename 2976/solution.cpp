/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 



long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));
    for (int i = 0; i < (int)cost.size(); i++) {
        int from = original[i] - 'a';
        int to = changed[i] - 'a';
        long long dist = cost[i];
        if (from == to) {
            continue;
        } else {
            dp[from][to] = dist;
        }
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dp[i][k] == LLONG_MAX || dp[k][j] == LLONG_MAX ) {
                    continue;
                } else {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                
            }
        }
    }

    long long totalCost = 0;
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == target[i]) {
            continue;
        } else {

            long long wt = dp[source[i] - 'a'][target[i] - 'a'];
            if (wt == LLONG_MAX) return -1;
            totalCost += wt;
        }
    }
    return totalCost;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        string source, target; cin >> source >> target;
        int n; cin >> n;
        vector<char> original(n); for (int i = 0; i < n; i++) cin >> original[i];
        vector<char> changed(n); for (int i = 0; i < n; i++) cin >> changed[i];
        vector<int> cost(n); for (int i = 0; i < n; i++) cin >> cost[i];

        cout << minimumCost(source, target, original, changed, cost) << endl;
    }
    return 0;
}