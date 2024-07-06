#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    
    // vector<int>candies;
    int count_2 = 0;
    int count_1 = 0;
    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      
      if(a == 1) count_1++;
      else count_2++;
    }

    int sum = count_2 * 2 + count_1;
    if(sum % 2 == 1){
      cout << "NO" << endl; 
      continue;
    } 

    sum /= 2;
    // if the sum is even we need to guarantee that the number of 1's 
    if(sum % 2 == 0 or (sum % 2 == 1 && count_1 != 0)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
 
  return 0;
}