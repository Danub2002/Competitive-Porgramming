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
int maxN  = 2e5 + 10, n, ans = 0;
vector<vector<int>>adj(maxN);
vector<int>used(maxN);

void dfs(int v, int par = -1){
    for(int u:adj[v]){
        if(u == par)continue;

        dfs(u,v);
		// Queremos pegar sempre as folhas primeiro
		// Por isso escolhemos pegar depois de chamar a dfs, pq qnd a dfs termina vai ser num vertice folha
        if(!used[u] && !used[v]){
            used[u] = used[v] = 1;
            ans++;
        }
    }
}
void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

	
    dfs(0);

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


