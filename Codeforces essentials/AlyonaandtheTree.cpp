#include<bits/stdc++.h>
using namespace std;

void dfs(int s, int p, vector<int> &cst, vector<vector<pair<int,int>>> &g, int &cnt, long long tc){
    if(tc>cst[s])
        return;
    cnt++;
    for(int i=0;i<g[s].size();i++){
        if(g[s][i].first==p) continue;
        dfs(g[s][i].first, s, cst, g, cnt, max((tc+g[s][i].second),(long long)0));
    }
}

int main(){
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);  
    int v;
    cin>>v;
    vector<int> cst(v+1,0);
    for(int i=1;i<=v;i++)
        cin>>cst[i];
    vector<vector<pair<int,int>>> g(v+1);
    int p, ev;
    for(int i=2;i<=v;i++){
        cin>>p>>ev;
        g[i].push_back({p,ev});
        g[p].push_back({i,ev});
    }
    int cnt = 0;
    dfs(1, -1, cst, g, cnt, 0);
    cout<<v-cnt;
}