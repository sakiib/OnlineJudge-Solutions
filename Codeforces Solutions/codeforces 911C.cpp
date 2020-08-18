#include <bits/stdc++.h>
#define MOD 1000000007
#define PLL pair <long long,long long>
#define LL long long
using namespace std;

LL ara[100005],tree_1[263000],tree_2[263000],lazy[263000];

void build (LL pos,LL L,LL R)
{
    if (L==R) {
        tree_1[pos]=ara[L];
        tree_2[pos]=(L*ara[L])%MOD;
        return;
    }

    LL x=pos*2,mid=(L+R)/2;
    build(x,L,mid);
    build(x+1,mid+1,R);

    tree_1[pos]=(tree_1[x]+tree_1[x+1])%MOD;
    tree_2[pos]=(tree_2[x]+tree_2[x+1])%MOD;
}

void propagate (LL pos,long long L,long long R)
{
    long long p,q,r,x=pos*2,mid=(L+R)/2;

    tree_1[x]=(tree_1[x]+lazy[pos]*(mid-L+1))%MOD;
    tree_1[x+1]=(tree_1[x+1]+lazy[pos]*(R-mid))%MOD;

    p=(L*(L-1))/2;
    q=(mid*(mid+1))/2;
    r=(R*(R+1))/2;
    tree_2[x]=(tree_2[x]+((q-p)%MOD)*lazy[pos])%MOD;
    tree_2[x+1]=(tree_2[x+1]+((r-q)%MOD)*lazy[pos])%MOD;

    lazy[x]=(lazy[x]+lazy[pos])%MOD;
    lazy[x+1]=(lazy[x+1]+lazy[pos])%MOD;
    lazy[pos]=0;
}

void update (LL pos,long long L,long long R,LL l,LL r,long long d)
{
    if (l>R || L>r) return;
    if (L>=l && R<=r) {
        long long p,q;
        q=(R*(R+1))/2;
        p=(L*(L-1))/2;

        tree_1[pos]=(tree_1[pos]+d*(R-L+1))%MOD;
        tree_2[pos]=(tree_2[pos]+((q-p)%MOD)*d)%MOD;
        lazy[pos]=(lazy[pos]+d)%MOD;

        return;
    }

    if (lazy[pos]!=0) propagate(pos,L,R);

    LL x=pos*2,mid=(L+R)/2;
    update(x,L,mid,l,r,d);
    update(x+1,mid+1,R,l,r,d);
    tree_1[pos]=(tree_1[x]+tree_1[x+1])%MOD;
    tree_2[pos]=(tree_2[x]+tree_2[x+1])%MOD;
}

PLL query (LL pos,LL L,LL R,LL l,LL r)
{
    if (l>R || L>r) return make_pair(0,0);
    if (L>=l && R<=r) return make_pair(tree_1[pos],tree_2[pos]);

    if (lazy[pos]!=0) propagate(pos,L,R);

    long long x=pos*2,mid=(L+R)/2;
    PLL Y,Z;
    Y=query(x,L,mid,l,r);
    Z=query(x+1,mid+1,R,l,r);
    return make_pair((Y.first+Z.first)%MOD,(Y.second+Z.second)%MOD);
}

int main ()
{
    long long i,j,T,N,Q,l,r,x,d,ans;
    PLL temp;

    scanf ("%lld",&T);
    for (i=1;i<=T;i++) {
        scanf ("%lld %lld",&N,&Q);
        for (j=1;j<=N;j++) scanf ("%lld",&ara[j]);
        build(1,1,N);
        memset(lazy,0,sizeof(lazy));
        printf ("Case %lld:\n",i);
        for (j=0;j<Q;j++) {
            scanf ("%lld %lld %lld %lld",&d,&l,&r,&x);
            if (d==1) update(1,1,N,l,r,x);
            if (d==2) {
                ans=0;
                temp=query(1,1,N,l,r);
                ans=(temp.first+((temp.second-(temp.first*l)%MOD)*x))%MOD;
                ans=(ans+MOD)%MOD;
                printf ("%lld\n",ans);
            }
        }
    }
    return 0;
}
