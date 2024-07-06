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
const int inf = 1e18, maxN = 2500 + 5;

vector<pair<int,int>>adj[maxN];
vector<int>d(maxN,inf);
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        adj[a].push_back({b,-c});
    }

    
    int ok = 0, x = -1;
    d[0] = 0; // Td mundo que nao foi alcancado pelo vertice 0 vai ter distancia para infinito entao e so rodar a dfs de td mundo marcado para ver se chega em n
    
    for(int i = 0; i < n; i++){
        ok = 0;

        for(int v = 0; v < n; v++){
            if(d[v]==inf)continue; // n e alcancavel a partir de 0
            for(auto e:adj[v]){
                int u = e.first, w = e.second;
                if(d[v] + w < d[u]){
                    ok = 1;
                    d[u]= d[v] + w; 
                    x = u;
                }
            }
        }

        if(!ok){
            break;
        }
    }
    // Bellman-Ford converge com n-1 iteracoes
    // se dps de n iteracoes continua atualizando tem ciclo negativo

    if(ok){
        cout << "Tem Ciclo Negativo" <<endl;
        // x é o último vértice que teve a aresta relaxada na n-ésima iteração
        // Então 
        return;
    }

    
    cout << d[n-1] << endl;
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
