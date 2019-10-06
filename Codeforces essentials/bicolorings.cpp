#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define N 1000
typedef unsigned long long ll;
ll mod = 998244353;
ll dp[N][2*N][4];
using namespace std;
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    dp[0][1][0]=1;
    dp[0][2][1]=1;
    dp[0][2][2]=1;
    dp[0][1][3]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            if(j>=2){
                dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-2][2]+dp[i-1][j-1][3])%mod;
                dp[i][j][2] = (dp[i-1][j-1][0]+dp[i-1][j-2][1]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;
            }
            else{
                dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j-1][3])%mod;
                dp[i][j][2] = (dp[i-1][j-1][0]+dp[i-1][j][2]+dp[i-1][j-1][3])%mod;               
            }
            dp[i][j][3] = (dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3])%mod;
        }
    }

    ll ans = (dp[n-1][k][0]+ dp[n-1][k][1]+  dp[n-1][k][2]+  dp[n-1][k][3])%mod;
    cout<<ans;
}