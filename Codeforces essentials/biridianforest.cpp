#include<iostream>
#include<vector>
#include<climits>
#include<map>
// #include<algorithm>
// #include<string>
// #include<stack>
#include<queue>
// #include <fstream>
using namespace std;

bool isSafe(vector<vector<char>> &g, vector<vector<bool>> &vis, int i, int j){
    return (i>=0) && (j>=0) && (i<g.size()) && (j<g[0].size()) && (g[i][j]!='T') && (!vis[i][j]);
}

void bfs(vector<vector<char>> &g, int re, int ce, map<int,int> &m, int &ld){
    vector<vector<bool>> vis(g.size(), vector<bool> (g[0].size(), 0));
    queue<pair<int,int>> q;
    q.push({re, ce});
    vis[re][ce]=1;
    int nc = 0;
    int l=0;
    pair<int,int> p;
    int x,y;
    while(!q.empty()){
        nc=q.size();
        l++;
        while(nc>0){
            p=q.front();
            q.pop();
            x=p.first;
            y=p.second;
            if(g[x][y]=='S')
                ld=l;
            else{
                if(g[x][y]-'0'!=0 && g[x][y]!='E'){
                    m[l]+=g[x][y]-'0';
                    // cout<<l<<" "<<g[x][y]<<endl;
                }
            }
            
            if(isSafe(g, vis, x-1, y)){
                vis[x-1][y]=1;
                q.push({x-1, y});
            }
            if(isSafe(g, vis, x+1 , y)){
                vis[x+1][y]=1;
                q.push({x+1, y});
            }
            if(isSafe(g, vis, x , y-1)){
                vis[x][y-1]=1;
                q.push({x, y-1});
            }
            if(isSafe(g, vis, x , y+1)){
                vis[x][y+1]=1;
                q.push({x, y+1});
            }
            nc--;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  

    int r, c;
    cin>>r>>c;
    vector<vector<char>> g(r, vector<char> (c));
    int re, ce;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>g[i][j];
            if(g[i][j]=='E'){
                re=i;
                ce=j;
                // cout<<i<<" "<<j<<endl;
            }
        }
    }

    map<int,int> m;
    int ld;
    int ans = 0;
    bfs(g, re, ce, m, ld);   
    // cout<<"apna londa "<<ld<<endl;    
    map<int,int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        // cout<<"dist "<<it->first<<" londe "<<it->second<<endl;
        if(it->first<=ld){
            ans+=it->second;
        }
    }
    cout<<ans<<endl;
}