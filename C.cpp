#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mod = 1e9+ 7;
const int dx[] = { 1, 0, -1, 0 };                                                            
const int dy[] = { 0, 1, 0, -1 };     

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
const int maxN = 1e5 + 5, inf = 1e16;
vector<pair<int,int>>adj[maxN];
priority_queue<int>best[maxN];
int n,m,k;


void solve() {
   cin >> n >> m >>k;
   for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >>c;
        a--,b--;
        adj[a].push_back({b,c});
    }

    // best[i] => mnores custos para chegar em i no max k

    // vector<int>d(n,inf);
    best[0].push(0);
    set<pair<int,int>>q;
    // d[0] = 0;
    q.insert({0,0});
    while(!q.empty()){
        int v= q.begin()->second, cost = q.begin()->first;
        q.erase(q.begin());

        // if(cost > best[v].top())continue;
        for(auto e:adj[v]){
            int u  =e.first, w = e.second;

            if(best[u].size() < k){
                best[u].push(cost + w);
                q.insert({cost + w, u});
            }
            else if(w + cost < best[u].top()){
                best[u].pop();
                best[u].push(cost + w);
                q.insert({cost + w, u});
            }
        }
    }
    
    vector<int>ans;
    while(best[n-1].size()){
        ans.push_back(best[n-1].top());
        best[n-1].pop();
    }

    reverse(all(ans));
    for(int i:ans)cout << i << " ";
}   


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
   
    while(t--) {
        solve();
    }
    return 0;
}


