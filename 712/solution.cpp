/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 

int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    sum += i; cnt++;
                    if (i !=  num / i) {
                        sum += (num / i); cnt++;
                    }   
                }
            }
            if (cnt == 4) {
                ans += sum;
            }
        }
        return ans;
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
        cout << sumFourDivisors(a) << endl;
    }
    return 0;
}