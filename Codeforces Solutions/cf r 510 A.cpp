#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;
#define pb push_back
#define F first
#define S second
#define M6 3000009
#define M5 3000009
#define pi 3.14159265
typedef pair<ll,ll> pll;
ll power(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1) ret=(ret*x);
        x=(x*x);
        n/=2;
    }
    return ret;
}
ll m,n,ar[M5],cr[M5],tree[M6],ql[M5],qr[M6];
void update(ll st,ll en,ll nd,ll i,ll v){
    if(st==en) {tree[nd]+=v; return;}
    ll mid=(st+en)/2;
    if(i>=st&&i<=mid){
        update(st,mid,2*nd,i,v);
    }
    else update(mid+1,en,2*nd+1,i,v);
    tree[nd]=tree[2*nd]+tree[2*nd+1];
}
ll query(ll st,ll en,ll nd,ll qs,ll qe){
    if(st>qe||en<qs) return 0;
    if(st>=qs&&en<=qe) return tree[nd];
    ll mid=(st+en)/2;
    ll p=query(st,mid,2*nd,qs,qe);
    ll q=query(mid+1,en,2*nd+1,qs,qe);
    return p+q;
}
int  main()
{   ios_base::sync_with_stdio (0), cin.tie (0);

    ll test=1,t=1,flag,i,j,k,l,a,b,ans=0,p,q;

    cin>>n>>test;

    vector<ll> v;
    for(i=1;i<=n;i++) cin>>ar[i],ar[i]+=ar[i-1],v.pb(ar[i]);

    v.pb(0);

    for(i=1;i<=1;i++){
        //cin>>ql[i]>>qr[i];
        ql[i] = -200000000000000 , qr[i] = test-1;
        for(j=1;j<=n;j++) v.pb(ar[j]-ql[i]),v.pb(ar[j]-qr[i]);
    }
    sort(v.begin(),v.end());
    for(i=1;i<=1;i++){
        q=(ll)v.size();
        j=lower_bound(v.begin(),v.end(),0)-v.begin();
        update(0,q,1,j,1);
        ans=0;
        for(j=1;j<=n;j++){
            a=ar[j]-qr[i]; b=ar[j]-ql[i];
            a=lower_bound(v.begin(),v.end(),a)-v.begin();
            b=lower_bound(v.begin(),v.end(),b)-v.begin();
            ans+=query(0,q,1,a,b);
            k=lower_bound(v.begin(),v.end(),ar[j])-v.begin();
            update(0,q,1,k,1);
        }
        j=lower_bound(v.begin(),v.end(),0)-v.begin();
        update(0,q,1,j,-1);
        for(j=1;j<=n;j++){
            k=lower_bound(v.begin(),v.end(),ar[j])-v.begin();
            update(0,q,1,k,-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
