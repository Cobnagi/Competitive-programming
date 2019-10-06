/*
given array [15, 10, 6], find min no of elements such that when their sign is fliped total sum is minimized;
find min elements to achieve sum = sum(Array)/2
*/

#define ll long long
int Solution::solve(const vector<int> &A) {
    int s = 0;
    for(int i=0;i<A.size();i++)
        s+=A[i];
    s=s/2;
    
    vector<vector<ll>> dp(A.size()+1, vector<ll> (s+1, INT_MAX));
    
    for(int i=0;i<dp.size();i++)
        dp[i][0]=0;
        
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<=s;j++){
            if(j>=A[i-1]){
                if(dp[i-1][j-A[i-1]]!=INT_MAX){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-A[i-1]]+1);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    ll ans=0;
    for(int i=s;i>=1;i--){
        if(dp[dp.size()-1][i]!=INT_MAX){
            ans=dp[dp.size()-1][i];
            break;
        }
    }
    return ans;
}
