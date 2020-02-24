class Solution {
public:
    
    int hist(vector<int> &h){
        int ans=0;
        stack<int> s;
        int i=0;
        for(i=0;i<h.size();i++){
            if(s.empty() || h[i]>=h[s.top()]){
                s.push(i);
            }
            else{
                while(!s.empty() && h[i]<h[s.top()]){
                    int top=s.top();
                    s.pop();
                    if(s.empty()){
                        ans = max(ans, h[top]*i);
                    }
                    else{
                        ans = max(ans, h[top]*(i-1-s.top()));
                    }
                }
                s.push(i);
            }
        }
            while(!s.empty()){
                int top=s.top();
                s.pop();
                if(s.empty()){
                   ans = max(ans, h[top]*i);
                }
                else{
                   ans = max(ans, h[top]*(i-1-s.top()));
                }
            }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& m) {
        if(m.size()==0 || m[0].size()==0) return 0;
        vector<vector<int>> v(m.size(), vector<int> (m[0].size()));
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                v[i][j] = m[i][j]-'0';
            }
        }
        
        for(int j=0;j<m[0].size();j++){
            for(int i=1;i<m.size();i++){
                if(v[i][j]!=0){
                    v[i][j]+=v[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<m.size();i++){
            ans = max(ans, hist(v[i]));
        }
        
        return ans;
    }
};