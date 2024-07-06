#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mod = 998244353;
const int dx[] = { 1, 0, -1, 0 };                                                            
const int dy[] = { 0, 1, 0, -1 };     

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

const int maxN = 20, inf = 1e9;
int n,m,k;
vector<vector<pair<int,int>>>adj(maxN);
vector<vector<int>>adj2(maxN);

void solve() {
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++){
        int x,y,c;
        cin >> x >> y >> c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    for(int i = 1; i<= n; i++){

        for(int j = i+1; j <= n; j++){
            adj[i].push_back({j,1});
            adj[j].push_back({i,1});

            adj2[i].push_back(j);
            adj2[j].push_back(i);
        }
    }

    vector<int>vis(maxN), d2(maxN);
    queue<int>q1;
    vis[1] = 1;
    d2[1] = 0;
    q1.push(1);
  
    while(!q1.empty()){
        int v = q1.front();
        q1.pop();

        for(int u:adj2[v]){
            if(!vis[u]){
                d2[u] = d2[v] + 1;
                q1.push(u);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i<= n; i++){
        for(int j=1; j <= n; j++)ans = max(ans, abs(d2[i] - d2[j]));
    }
    cout << "ans: " << ans << endl;
    for(int s = 1; s <= n; s++){
        for(int t = s+1; t <= n; t++){
            if(abs(d2[s] - d2[t]) > m)continue;
            // set<pair<int,int>>q;
            priority_queue<pair<int,int>,vector<pair<int,int>>>q;
            vector<int>d(maxN,inf),vis2(maxN);
            // q.insert({0,s});
            q.push({0,s});
            d[s] = 0;
            while(!q.empty()){
                
                int v= q.top().second;
                // q.erase(q.begin());
                cout << "v: " << v << " dv:  "  << d[v] << endl;
                q.pop();

                if(vis[v])continue;
                vis[s] = 1;
                for(auto e:adj[v]){
                    int u = e.first, w = e.second;
                    cout << "u: " << u << " w: " << w << endl;
                    if(d[u] > d[v] + w){
                        d[u] = d[v] + w;
                        q.push({d[u],u});

                    }
                }
            }

            if(d[t] != inf)ans = max(ans,d[t]);            
        }
    }

    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


