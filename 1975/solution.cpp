/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
// bool isValid(int i, int j, int n) {
//     return i < n && j < n;
// }

// vector<vector<int>> directions {
//     {0, 1},
//     {1, 0}
// };

// long long f(int x, int y, int n, long long sumSoFar, vector<vector<int>>& a) {

//     // compute ans
    
//     long long ans = LLONG_MIN;

//     // traverse
//     for (vector<int> direction: directions) {
//         int newX = x + direction[0], newY = y + direction[1];
//         if (isValid(newX, newY, n)) {
//             long long sum = f(newX, newY, n, a);
//             ans = max(ans, sum);
//         }
//     }
//     return ans;
// }

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    long long sum = 0;
    int nCnt = 0, pCnt = 0;
    int smallestN = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] >= 0) {
                pCnt++;
            } else {
                smallestN = min(smallestN, abs(matrix[i][j]));
                nCnt++;
            }
            sum += abs(matrix[i][j]);
        }
    }
    if (nCnt % 2 == 0) {
        return sum;
    } 
    return sum - smallestN - smallestN;
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
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        cout << maxMatrixSum(a) << endl;
    }
    return 0;
}