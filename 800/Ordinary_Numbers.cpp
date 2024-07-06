#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;

    int ans = 0;
    for(int d = 1; d <= 9; d++){
      for(int k = 0; k <= 8; k++){
        
        if(d*pow(10,k) + 1 <= n){
          ans++;
        }
      }
    }

    if(n < 10){
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}