int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size()==0)
        return 0;
    vector<int> incr(A.size(),1);
    vector<int> decr(A.size(),1);
    
    for(int i=0;i<incr.size();i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j])
                incr[i]=max(incr[i],incr[j]+1);
        }
    }
    
    for(int i=A.size()-2;i>=0;i--){
        for(int j=A.size()-1;j>i;j--){
            if(A[i]>A[j])
                decr[i] = max(decr[j]+1,decr[i]);
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<A.size();i++){
        ans = max(ans,incr[i]+decr[i]-1);
    }
    return ans;
}