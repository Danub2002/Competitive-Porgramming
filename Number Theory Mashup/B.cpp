#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void solve(){
  vector<int>a = {1};
  a.back() += 1;
  cout << a[0] << endl;
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int t;
  cin >> t;
  // t = 1;
  
  while(t--){
    solve();
  }
  return 0;
}