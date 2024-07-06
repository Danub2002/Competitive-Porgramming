#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void solve(){
  int n;
  cin >> n;

  // se x divide y e x!= y, precisamos dividir y por alguma coisa e resultar em x, como x != y o menor numero que podemos dividir y é 2, o que resulta no maior x, então
  // x <= y/2

  // Entao para escolher o melhor par temos dois casos:
  // 1. n é par => (n,n/2)
  // 2. n é ímpar => (n-1,(n-1)/2)
  cout << n/2 << endl;
  
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