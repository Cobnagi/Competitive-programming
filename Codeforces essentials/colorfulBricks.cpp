#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int mod=998244353;
int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<ll>> dp(n, vector<ll> (n, 0));
    // dp[0][0]=1;
    // if(n>1){
    //     dp[1][0]=1;
    //     dp[1][1]=1;
    // }
    // for(int i=2;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         if(j==0||j==i)
    //             dp[i][j]=1;
    //         else
    //             dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+mod)%mod;
    //     }
    // }
    // ll ans = 1;
    // int h=k;
    // ll tmp = m-1;
    // while(h>0){
    //     if(h%2==1)
    //         ans = (ans * tmp + mod)%mod;
    //     h/=2;
    //     tmp = (tmp*tmp + mod)%mod;
    // }
    // ans = (ll)(((((ans*(ll)dp[n-1][k])%mod)*(ll)m)+mod)%mod);
    // cout<<ans<<endl;

}