#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int a,b;
    cin>>a>>b;
    int m=max(a,b);
    int k=6-m;
    if(k>=0) k++;
    int g=__gcd(k,6);
    cerr<<k<<endl;
    cerr<<g<<endl;
    cout<<k/g<<"/"<<6/g<<endl;
    return 0;
}
