#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl;
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mod = 1e9+ 7;
const int dx[] = { 1, 0, -1, 0 };                                                            
const int dy[] = { 0, 1, 0, -1 };     

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

void solve() {
    int n, tmp = 0;
    cin >> n;
    vector<int>a(n),cnt(4);
    for(int &i:a){
        cin >> i;
        cnt[i]++;

        tmp += i;
    }
    cout << fixed;
    int x = cnt[1] + cnt[2]+ cnt[3], y = cnt[2] + cnt[3], z = cnt[3];
    double dp[x + 1][y+ 1][z + 1]; 

    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            for(int k = 0; k <= z; k++)dp[i][j][k] = 0;
        }
    }
    // dp[i][j][k] => valor esperado de movimentos para tirar um sushi com i pratos com 1 sushi, j pratos com 2 e k pratos com 3
    // valor esperado de movimentos para sair um sushi agr => n/(i + j + k)
    // + a qnt de movimentos que ja fez pra chegar agora
    // tiro um sushi, mas ele pode vir de prato com 1, 2 ou 3 sushis
    // se vem de um prato de 1, dp[i-1][j][k]
    // se tiro de um prato de 2 vai ser dp[i+1][j-1][k]
    // se tiro de um prato com 3 vai ser dp[i][j+1][k-1]
    // mudar a ordem dos loops => retirar os com 3 sushi primeiro

    for(int k = z; k >= 0; k--){
        for(int j = y; j >= 0; j--){
            for(int i= x; i >= 0; i--){
                int s= i + 2*j + 3*k, plates = i + j + k;

                if(!s or s > tmp or plates > n)continue;
                dp[i][j][k] += (double)n/plates;
                // cout << "n/s: " <<  (double)n/plates << " dp: " << dp[i][j][k] << endl;

                // Multiplicar pela probabilidade de ir para aquele estado
                if(i)dp[i-1][j][k] += dp[i][j][k] * (double)i/plates;
                if(j)dp[i+1][j-1][k] += dp[i][j][k] * (double)j/plates; // estado (i+1,j-1,k) ainda nao foi computado
                if(k)dp[i][j+1][k-1] += dp[i][j][k] * (double)k/plates;
            } 
        }
    }

    for(int k = z; k >= 0; k--){
        for(int j = y; j >= 0; j--){
            for(int i= x; i >= 0; i--){
                cout << "i: "<< i << " j: " << j << " k: " <<k << " dp: " << dp[i][j][k] << endl;

            }
        }
    }
    cout << dp[0][0][0] << endl;
}   


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
   
    while (t--) {
        solve();
    }
    return 0;
}


