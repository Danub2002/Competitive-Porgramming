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
const int maxN = 1e5 +5;
vector<int>adj[maxN],parent(maxN),low(maxN),discovery(maxN,-1);
// set<pair<int,int>>brigdes;
int dfsIteration = 1;
void tarjan(int u,auto&brigdes){
	discovery[u] = low[u] =dfsIteration++;
    // cout << "u: " << u << " par: " << parent[u] << " disc: "<< discovery[u] << " low: "<< low[u]<< endl;
    
	for(int v:adj[u]){
		// Se v ainda nao foi visitado
		if(discovery[v] == -1){
			// Visita v e marca o pai dele como sendo u
			parent[v] = u;

			tarjan(v,brigdes);

			if(low[v] > discovery[u]){
				brigdes.insert({min(u,v), max(u,v)});
                cout << "Ponte: " << min(u,v) << " " << max(u,v) << endl;
			}


            low[u] = min(low[u],low[v]);
		}
		// se (u,v) for uma back-edge, mas v não é par de u, quer dizer q pode ter um outro caminho para chegar em v
		else if(v != parent[u]){
			low[u] = min(low[u],discovery[v]);
		}
	}

}
void solve(){
    int n,m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int k;
	cin >> k;
    while(k--){
        int a,b;
        cin >> a >> b;
        dfsIteration = 1;
        parent.clear(), low.clear();
        for(int i = 1; i <= n; i++)discovery[i] = -1;
        set<pair<int,int>>b1,b2;
        cout << "b1: " << endl;
        tarjan(a,b1);
        parent.clear(),low.clear();
        for(int i = 1; i <= n; i++)discovery[i] = -1;
        cout << "b2: " << endl;
        tarjan(b,b2);

        int ans =0;
        for(auto it:b1){
            if(b2.count(it))ans++;
        }

        cout << ans << endl;
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


