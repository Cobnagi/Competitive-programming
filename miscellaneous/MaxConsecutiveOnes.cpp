#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int l=0;
    int r=0;
    int ans=0;
    int cnt=0;
    int no=0;
    while(r!=n){
        if(v[r]==1){
            no++;
            r++;
            ans = max(ans, no);
        }
        else{
            cnt++;
            if(cnt==k){
                if(v[l]==0)
                    cnt--;
                else
                    no--;
                l++;
            }
            else
                r++;
        }
    }
    cout<<ans;
}