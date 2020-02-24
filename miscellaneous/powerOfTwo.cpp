#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a==0)
        cout<<"Yes"<<endl;
    else{
        if((a&(a-1))==0)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
}