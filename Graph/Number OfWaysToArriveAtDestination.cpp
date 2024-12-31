// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& grid) {
        vector <vector <pair <ll, ll>>> adj(n+1);
        for(auto x: grid) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        ll INF = 1e15;
        ll MOD = 1e9 + 7;
        vector<ll> dist(n+1, INF);
        vector<ll> steps(n+1, 0);
        steps[0] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, 0}); 
        while(!q.empty()) {
            ll dis = q.top().first;
            ll node = q.top().second;  
            q.pop();
            if (dis > dist[node]) continue;
            for(auto it : adj[node]) {
                ll crrNode = it.first;
                ll distFromParent = it.second;
                if(distFromParent + dis < dist[crrNode]) {
                    dist[crrNode] = distFromParent + dis;
                    steps[crrNode] = steps[node];
                    q.push({distFromParent + dis, crrNode}); 
                }
                else if(distFromParent + dis == dist[crrNode]) {
                    steps[crrNode] = (steps[crrNode] + steps[node]) % MOD;
                }
            }
        }
        return steps[n-1];
    }
};
