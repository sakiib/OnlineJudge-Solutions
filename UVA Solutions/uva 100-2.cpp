#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll a,b,mx,ans;


void solve(ll n)
{
    if(n==1) return;
    if(n%2==1){
        n=n*3+1;
        n=n/2;
        ans+=2;
        solve(n);
    }
    else{
        n=n/2; ans++;
        solve(n);
    }
}
int main()
{
    ll m,n;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        mx=0; ans=1;
        m=a,n=b;
        if(a>b) swap(a,b);
        while(a<=b){
            solve(a);
            mx=max(mx,ans);
            ans=1;
            a++;
        }
        cout<<m<< " " <<n<< " " <<mx<<endl;
    }
    return 0;
}
