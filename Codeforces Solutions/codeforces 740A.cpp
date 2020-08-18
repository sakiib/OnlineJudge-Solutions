#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,a,b,c,lagbe=0,ans,x,y,z;
    cin>>n>>a>>b>>c;
    if(n%4==0)
    {
        cout<<0<<endl; return 0;
    }
    while(n%4!=0)
    {
        n++;
        lagbe++;
    }
    if(lagbe==1)      ans=min(a,min(b+c,3*c));
    else if(lagbe==2) ans=min(2*a,min(b,2*c));
    else if(lagbe==3) ans=min(3*a,min(c,a+b));
    cout<<ans;
    return 0;
}
