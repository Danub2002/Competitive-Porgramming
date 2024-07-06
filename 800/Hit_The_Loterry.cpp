#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int n;
  cin >> n;
  vector<int>bills = {100,20,10,5,1};
  int ans = 0;
  for(int &bill:bills){
    ans += n / bill;
    n = n % bill;
  }

  cout << ans;
  return 0;
}