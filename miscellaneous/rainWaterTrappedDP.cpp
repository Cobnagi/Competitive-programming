#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
typedef unsigned long long ll;
#define f first
#define s second
vector<int> xr = {-2,-1,-2,-1,1,2,2,1};
vector<int> yc = {1,2,-1,-2,-2,-1,1,2};

int trap(vector<int>& h) {
    if(h.size()==0) return 0;
    vector<int> l=h;
    vector<int> r=h;
    l[0]=0;
    r[h.size()-1]=0;
    for(int i=1;i<h.size();i++){
        l[i] = max(l[i-1], h[i-1]);
    }
    for(int i=h.size()-2;i>=0;i--){
        r[i] = max(r[i+1], h[i+1]);
    }
    int ans=0;
    for(int i=0;i<h.size();i++){
        if((min(r[i], l[i])-h[i])>0){
            ans+=min(r[i], l[i])-h[i];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<trap(v)<<endl;
}