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
const int maxN = 50005;
int n;
vector<vector<int>>adj(maxN);
vector<int>sub(maxN),out_sub(maxN), d(maxN);

void dfs1(int v, int par= -1){

    for(int u:adj[v]){
        if(u==par)continue;

        dfs1(u,v);

        if(sub[u] + 1 > sub[v]){
            out_sub[v] = sub[v];
            sub[v] = sub[u] + 1;
        }
        else if(sub[u] + 1 > out_sub[v]){
            out_sub[v] = sub[u] + 1;
        }
    }
}

void dfs2(int v,int par = -1, int to_p = 0){
    d[v] = max(to_p, sub[v]);

    for(int u:adj[v]){
        if(u == par)continue;

        if(sub[u] + 1 == sub[v]){
            dfs2(u,v, max(to_p, out_sub[v]) + 1);
        }
        else dfs2(u,v,d[v] + 1);
    }
}
void solve() {
    
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }

    dfs1(0);
    dfs2(0);


    for(int i = 0; i < n; i++){
        cout << d[i] << " ";
    }

    
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


