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

const int maxN = 2e5 +5;
vector<int>adj[maxN],adj_rev[maxN],vis(maxN), visited_stack,scc;
int n,m;
void dfs(int u,auto&adj,auto&st){
    vis[u] = 1;
    for(int v:adj[u]){
        if(!vis[v]){
            dfs(v,adj,st);
        }   
    }

    st.push_back(u);
}
void kosaraju() {
    for(int i = 0; i < n; i++){
        if(!vis[i])dfs(i,adj,visited_stack);
    }

    vis.assign(maxN,0);
    for(int i = n-1; i >= 0; i--){
        int u = visited_stack[i];
        if(!vis[u]){
            scc.clear();
            dfs(u,adj_rev,scc);
            for(int v:scc)cout << v+1 <<  " ";
            cout << endl;
        }
    }
}   


void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    kosaraju();
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
