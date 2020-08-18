#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;

const int inf=1e9;
const LL INF=2e18;
const int N=100005;
const int MOD=1e9+7;

#define PI acos(-1.0)
#define EPS 1e-9
#define ff first
#define ss second
#define pb push_back
#define mp pake_pair
#define pp pop_back
#define CLR(V) V.clear()
#define SORT(V) sort(V.begin(),V.end())
#define REV(V) sort(V.rbegin(),V.rend())
#define MEM(a,x) memset(a,x,sizeof(a))
#define debug(x) cerr<<"X is : "<<x<<endl
#define here cerr<<"<===========>"<<endl

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=b;i>=a;i--)
#define REP(i,a) for(int i=0;i<a;i++)

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

int dx4[]={+1,-1,+0,+0};
int dy4[]={+0,+0,+1,-1};
int dx8[]={-1,+0,+1,+0,+1,+1,-1,-1,+0};
int dy8[]={+0,-1,+0,+1,+1,-1,+1,-1,+0};
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
//--------------------------------------------------------------

LL ara[N];
LL tree[N*4];

LL Query(LL Node,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return INF;
    if(b>=i&&e<=j) return tree[Node];
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    LL p1=Query(Left,b,mid,i,j);
    LL p2=Query(Right,mid+1,e,i,j);
    return min(p1,p2);
}
void Build(LL Node,LL b,LL e) {
    if(b==e) {
        tree[Node]=ara[b];
        return;
    }
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    Build(Left,b,mid);
    Build(Right,mid+1,e);
    tree[Node]=min(tree[Left],tree[Right]);
}
int main(int argc,char const *argv[]) {
    LL t,tc;
    scanf("%lld",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,q;
        scanf("%lld%lld",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        Build(1,1,n);
        printf("Scenario #%lld:\n",tc);
        while(q--) {
            LL l,r;
            scanf("%lld%lld",&l,&r);
            LL ans=Query(1,1,n,l,r);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

