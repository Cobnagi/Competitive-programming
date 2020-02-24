#include<iostream>
#include<climits>
using namespace std;
int main(){
    unsigned int a = 5;
    int aa = INT_MIN;
    long int b = 2341;
    long long int c = 301321;
    cout<<__builtin_popcount(a)<<endl;
    cout<<__builtin_popcount(aa)<<endl;
    cout<<__builtin_popcountl(b)<<endl;
    cout<<__builtin_popcountll(c)<<endl;
}