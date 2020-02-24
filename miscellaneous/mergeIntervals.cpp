#include <iostream>
#include<vector>
#include<algorithm>
#define ff first
#define ss second
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return (a.ss<b.ss);
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int p;
        cin>>p;
        vector<pair<int,int>> v(p);
        int x,y;
        for(int i=0;i<p;i++){
            cin>>x>>y;
            v[i]={x,y};
        }
        sort(v.begin(), v.end(), comp);
        //     for(int i=0;i<v.size();i++)
        // cout<<v[i].ff<<" "<<v[i].ss<<" ";
    vector<pair<int,int>> ans;
    int i=p-1, j=p-2;
    int bak;
    int frnt;
    while(i>=0 && j>=0){
        bak=v[i].ss;
        frnt=v[i].ff;
        while(j>=0 && v[j].ss>=frnt){
            v[j].ss;
            frnt=min(frnt, v[j].ff);
            j--;
        }
        ans.push_back({frnt, bak});
        i=j;
        j=j-1;
    }
    if(i>=0){
        ans.push_back({v[i].ff, v[j+1].ss});
    }
    sort(ans.begin(), ans.end());
    for(int k=0;k<ans.size();k++)
        cout<<ans[k].ff<<" "<<ans[k].ss<<" ";
    cout<<endl;
    }
}