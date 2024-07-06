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
- Para cada vértice não visitado rodar uma DFS:
    . Marcar u como visitado
    . Visitar tds os vizinhos de u nao visitados
    . Guardar u em uma pilha

- Para cada vértice da pilha que não foi visitados por essa segunda DFS, rodar uma DFS no grafo com as arestas reversas

- Os vertices visitados com cada DFS no grafo transposto serão uma componente fortemente conexa
- A cada DFS no grafo reverso representa um SCC
*/

const int maxN = 2e5 +5, inf =1e16;
vector<pair<int,int>>adj[maxN],adj_rev[maxN];
vector<int>path(maxN);
int n,m;

vector<int> dijkstra(auto &adj, int s){
	/*
		Version using set
		when relaxing the distance we erase the previous distance found
	*/
	vector<int>d(n,inf);
	set<pair<int,int>>q;
	d[s]= 0;
	q.insert({d[s],s});
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());

		for(auto e:adj[v]){
			int u = e.first, w = e.second;

			if(d[v] + w < d[u]){
				q.erase({d[u],u});
				path[u] = v;
				d[u] = d[v] + w;
				q.insert({d[u],u});
			}
		}
	}

	return d;
}
vector<int> dijkstra(auto &adj, int s){
	/*
		Version using min priority queue
		We dont erase the previous distance form the queue, but we need to check if had already been visited
	*/
	vector<int>d(n,inf),vis(n);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	d[s]= 0;
	q.push({d[s],s});
	while(!q.empty()){
		int v = q.top().second;
		q.pop();

		if(vis[v])continue;
		// this if whe can change to: if(d_v != d[v])
		vis[v] =1;
		for(auto e:adj[v]){
			int u = e.first, w = e.second;

			if(d[v] + w < d[u]){
				path[u] = v;
				d[u] = d[v] + w;
				q.push({d[u],v});
			}
		}
	}

	return d;
}

struct Edge{
	int v,to,w;
};
void solve(){
    cin >> n >> m;
	vector<Edge>edges;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >>c;
        a--,b--;
        adj[a].push_back({b,c});
        adj_rev[b].push_back({a,c});

		Edge e;
		e.v = a, e.to = b, e.w = c;
		edges.push_back(e);
    }

    vector<int>d,d_rev;
	d = dijkstra(adj,0);
	d_rev = dijkstra(adj_rev,0);

	// Create DAG of shortests path
	for(auto e:edges){
		int v = e.v, u = e.to, w = e.w;

		if(d[v] + w + d_rev[u] == d[n-1]){
			// Belongs to a Shortest Path
		}
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
