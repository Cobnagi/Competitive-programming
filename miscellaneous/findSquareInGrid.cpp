class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));
        int ans = 0;
        for(int i=0;i<dp.size();i++){
            dp[i][0] = matrix[i][0]-'0';
            if(dp[i][0]==1)
                ans=1;
        }
        for(int j=0;j<matrix[0].size();j++){
            dp[0][j] = matrix[0][j]-'0';
            if(dp[0][j]==1)
                ans=1;
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]!='0'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};