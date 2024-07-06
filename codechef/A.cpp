#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void solve(){
  int x,y;
  cin >>x >> y;

  // minimizar a soma dos subarrays
  
  int n = x + y;
  int begin = n/2 - y/2;
  cout << max(begin, x + (-2)*y)<< endl;
   
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