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

const int maxN = 2e5 + 5, inf = 1e9;
vector<pair<int,int>>adj[maxN],vis(maxN),in(maxN);
int n,m,ok =1;

void solve() {
    cin >> n >> m;
    for(int i= 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >>c;

        adj[a].push_back({b,c});
    }

    // Dijkstra => pego o menor custo
    // Manter as ditancias para cada no
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