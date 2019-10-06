#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    int u;
    for(int i=2;i<=n;i++){
        cin>>u;
        g[i].push_back(u);
    }
    vector<int> ans;
    u=n;
    while(1){
        ans.push_back(u);
        if(u==1)    
            break;
        u = g[u][0];
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
    cout<<endl;
}