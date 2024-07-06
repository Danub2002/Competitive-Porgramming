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
const int maxN = 1e5 + 5;
int n,m;

vector<vector<int>>adj_rev(maxN);
vector<int>out(maxN);

void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >>b;
        a--,b--;
        out[a]++;
        adj_rev[b].push_back(a);
    }

    // Longest path on DAG => TopoSort?
    // Oderna por grau de saida
    vector<int>a;
    queue<int>q;
    for(int i = 0; i < n; i++){
        if(!out[i]){
            q.push(i);
            a.push_back(i);
        }
    }

    while(!q.empty()){
        int v =q.front();
        q.pop();

        for(int u:adj_rev[v]){
            if(--out[u] == 0){
                q.push(u);
                a.push_back(u);
            }
        }
    }
    reverse(all(a));
    vector<int>dp(n);
    for(int i = 0; i < n; i++){
        int v = a[i];
        for(int u:adj_rev[v])dp[v] = max(dp[v],dp[u] + 1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)ans = max(ans,dp[i]);
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


