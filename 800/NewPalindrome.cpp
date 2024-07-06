#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;

    // every palindrome is refleted to the mid of the srtring
    // if the substrings of the left and right of the palindrome
    // has the number of dif chars equal to 0 we dont have another palindrome
    int mid = s.size()/2;
    
    int dif = 0;
    for(int i = 1; i < mid;i++){
      if(s[i] != s[i-1]) dif++;
    }

    if(dif == 0){
      cout << "NO" << endl;
    }else{
      cout << "YES"<< endl;
    }
  }
 
  return 0;
}