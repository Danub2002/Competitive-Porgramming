#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int n;
  cin >> n;
  vector<int>arr;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    arr.push_back(a);
  }
  
  // vector<int>dp(n);
  // dp[0] = 1;
  int ans = 1,temp = 1;
  for(int i = 1; i < n; i++){
    
    if(arr[i] > arr[i-1]){
      temp++;
    }
    else{
      ans = max(ans,temp);
      temp = 1;
    }
  }

  cout << max(ans,temp);
  return 0;
}