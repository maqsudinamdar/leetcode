/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 

int topDown(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i - 1] == s2[j - 1]) {
        return dp[i][j] = 1 + topDown(i - 1, j - 1, s1, s2, dp);
    }
    int x = topDown(i - 1, j, s1, s2, dp);
    int y = topDown(i, j - 1, s1, s2, dp);

    return dp[i][j] = max(x, y);
}

int f(int i, int j, string s1, string s2) {
    if (i == 0 || j == 0) return 0;

    if (s1[i - 1] == s2[j - 1]) {
        return 1 + f(i - 1, j - 1, s1, s2);
    }
    int x = f(i - 1, j, s1, s2);
    int y = f(i, j - 1, s1, s2);

    return max(x, y);
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    // return f(m, n, text1, text2);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return topDown(m, n, text1, text2, dp);
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        string s1, s2; cin >> s1 >> s2;
        cout <<  longestCommonSubsequence(s1, s2) << endl;
    }
    return 0;
}