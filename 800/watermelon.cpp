#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int n;
  cin >> n;

  if((n-2)%2 == 0 && n > 2){
    cout << "YES";
    return 0;
  }
  
  cout << "NO";
  return 0;
}