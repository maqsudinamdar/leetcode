/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 

long long dijkstra(char source, char target, vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source - 'a'});
    vector<long long> dist(26, LLONG_MAX);
    dist[source - 'a'] = 0;
    while(!minHeap.empty()) {
        auto node = minHeap.top();
        int d = node.first; int ch = node.second;
        minHeap.pop();
        if (ch == target) break;
        if (d > dist[ch]) {
            continue;
        }
        for (auto &edge: adj[ch]) {
            int v = edge.first; int weight = edge.second;
            if (d + weight < dist[v]) {
                dist[v] = d + weight;
                minHeap.push({dist[v], v});   
            }
            
        } 
    } 
    // cout << dist[target - 'a'] << endl;
    return dist[target - 'a'];
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    long long totalCost = 0;
    vector<vector<pair<int, int>>> adj(26);
    for (int i = 0; i < (int)cost.size(); i++) {
        int ele = original[i] - 'a';
        adj[ele].push_back({changed[i] - 'a', cost[i]});
    }

    map<string, int> memo;

    int size = source.size();
    for (int i = 0; i < size; i++) {
        if (source[i] != target[i]) {
            string combination;
            combination.push_back(source[i]);
            combination.push_back(target[i]);
            if (memo.find(combination) != memo.end()) {
                totalCost += memo[combination];
            } else {
                long long dist = dijkstra(source[i], target[i], adj);
                if (dist == LLONG_MAX) return -1;
                memo[combination] = dist;
                totalCost += dist;
            }
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