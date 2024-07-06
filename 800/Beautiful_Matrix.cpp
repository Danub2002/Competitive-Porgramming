#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int ans;
  for(int i = 1; i <= 5; i++){
    for(int j = 1; j <= 5; j++){
      // cin >> matrix[i][j];
      int a;
      cin >> a;
      if(a == 1){
        ans = abs(i - 3) + abs(j-3);
        
      }
    }
  }
  cout << ans;
  
  return 0;
}