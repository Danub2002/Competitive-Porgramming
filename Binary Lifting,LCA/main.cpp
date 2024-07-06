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
const int maxN = 1e5 + 5, inf = 1e16, LOGN = 20;
vector<pair<int,int>>adj[maxN];

int lift[maxN][LOGN];
int n,m,k;

/*
Binary Lifting: Realizar saltos de tamanho k em uma árvore enraizada

*/

void dfs(int v){

}
void solve() {
	int n;
	cin >> n;
	vector<int>p(n);
	p[0] = -1;
	for(int i = 1; i < n; i++)cin >> p[i];

	memset(lift, -1, sizeof lift);
	for(int i = 1; i < n; i++)lift[i][0] = p[i];

	for(int k = 1; k < LOGN; k++){
		// Invariante: ja computei lift[....][k-1]
		for(int i =0; i < n; i++){
			
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


