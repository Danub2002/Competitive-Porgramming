#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mod = 1e9+ 7;
const int dx[] = { 1, 0, -1,0};                                                            
const int dy[] = { 0, 1, 0, -1 };     


int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}


/* 
- Para cada Vertice durante a DFS:
	. discovery(v) -> iteracao da primeira visita ao vértice v
	. low(v) -> menor valor de discovery alcançável na subárvore com raiz em v

- Apos visitar cada vértice u adjacente nao visitado, iremos atualizar o valor de low(v) para min(low(v),discovery(u))

- Dados dois vértices adjacentes, u e v, se low(v) >= discovery(u), então u é uma articulação

- Se low(v) < discovery(u), então é possível chegar em u a partir de v por outro caminho

- Se u é a raiz da DFS, ele só é articulação se tem mais de um filho na sua subárvore
*/

const int maxN = 2e5 +5;
vector<int>adj[maxN],adj_rev[maxN],parent(maxN),low(maxN,1e9),discovery(maxN,-1),is_articulation(maxN);
set<pair<int,int>>brigdes;
int dfsIteration = 1;
void tarjan(int u, int root){
	discovery[u] = low[u] =dfsIteration++;
	int children = 0;
	for(int v:adj[u]){
		// Se v ainda nao foi visitado
		if(discovery[v] == -1){
			// Visita v e marca o pai dele como sendo u
			parent[v] = u;
			children++;

			tarjan(v,root);

			// Verifica se u é uma articulação
			if(low[v] >= discovery[u] && u != root){
				is_articulation[u] = true;
			}

			if(low[v] > discovery[u]){
				brigdes.insert({min(u,v), max(u,v)});
			}
		}
		// se (u,v) for uma back-edge, mas v não é par de u, quer dizer q pode ter um outro caminho para chegar em v
		else if(v != parent[u]){
			low[u] = min(low[u],discovery[v]);
		}
	}

	if(u == root && children > 1)is_articulation[u] = true;
}
void solve() {
    int n,m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >>b;
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
	}
	

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
