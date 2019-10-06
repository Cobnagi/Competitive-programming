#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
typedef unsigned long long ll;
using namespace std;
int dp[1000001];
int v[1000001];
int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    for(int i=0;i<1000001;i++) v[i]=0;
    int n;
    cin>>n;
    int x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v[x]=y;
    }
    int ans=0;
    if(n==1)
        cout<<0<<endl;
    else{
        for(int i=0;i<1000001;i++){
            if(i-v[i]-1>=0){
                if(v[i]!=0)
                    dp[i]=dp[i-v[i]-1]+1;
                else
                    dp[i]=dp[i-1];
                ans=max(ans, dp[i]);
            }
            else{
                if(v[i]>0)
                    dp[i]=1;
                else
                    dp[i]=0;
                ans=max(ans, dp[i]);
            }
        }
        cout<<n-ans<<endl;
    }
}