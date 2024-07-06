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
const int N = 2e5 + 1;
int par[N], sz[N];

void init(){
	for(int i = 0; i < N; i++){
		par[i] = i, sz[i] = 1;
	}
}

int find(int a){
	return (par[a] == a? a: find(par[a]));
}

void unite(int a,int b){
	a = find(a), b = find(b);
	if(a == b)return;
	if(sz[a] > sz[b])swap(a,b);

	par[a] = b;
	sz[b] += sz[a];

}

// O(n log n)
void solve() {

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


