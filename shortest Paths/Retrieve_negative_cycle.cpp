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
const int maxN = 2500 + 5, inf = 1e16;
vector<pair<int,int>>adj[maxN];
int n,m;

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >>c;
        a--,b--;
        adj[a].push_back({b,c});
    }

    
    vector<int>d(n,inf),par(n,-1);

    for(int s= 0; s < n; s++){
 
        if(d[s] != inf)continue;
        d[s] = 0;
        int ok = 0, x = s; // Ou está em um ciclo negativo ou é alcançável a partir dele
        for(int i = 0; i < n; i++){
            ok = 0;
            for(int v = 0; v < n; v++){
                if(d[v] == inf)continue;

                for(auto e: adj[v]){
                    int u = e.first, w = e.second;
                    
                    if(d[v] + w < d[u]){
                        ok = 1;
                        d[u] = d[v] + w;
                        par[u] = v, x = u;
                    }
                }
            }

            if(!ok){
                break;
            }
        }

        if(ok){
            // N convergiu com n-1 iteracoes => ciclo negativo
            cout << "YES" << endl;
            
            // como temos ctz que x é alcançável pelo ciclo podemos procurar o vértice mais próximo do source que está no ciclo buscando pelos pais n vezes
            int y = x;
            for(int i = 0; i < n; i++)y = par[y];

            vector<int>ans;
            ans.push_back(y);
            int cur= par[y];
            while(cur != y){
                ans.push_back(cur);
                cur = par[cur];
            }
            ans.push_back(y);

            reverse(all(ans));
            for(int i:ans)cout << i+1 << " ";
            cout <<endl;
            return;
        }
    }
    cout << "NO" <<endl;
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


