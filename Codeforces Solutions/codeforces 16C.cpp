#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll x,y,a,b,m,n,gcd,ans;
    cin>>x>>y>>a>>b;
    gcd=__gcd(a,b);
    a=a/gcd;
    b=b/gcd;
    m=x/a;
    n=y/b;
    ans=min(m,n);
    cout<<a*ans<< " " <<b*ans<<endl;
    return 0;
}
