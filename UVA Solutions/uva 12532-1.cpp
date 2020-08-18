#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

#define FOR1(i,a,b)     for(int i=a; i<=b ;i++)
#define FOR0(i,a)       for(int i=0; i<a ;i++)
#define CLR(a,n)        FOR0(i,n) a[i].clear()
#define MEM(a,x)        memset(a, x ,sizeof(a))

#define scanI(a)        scanf("%d",&a)
#define scanI2(a,b)     scanI(a), scanI(b)
#define scanI3(a,b,c)   scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)        scanf("%lld",&a)
#define scanL2(a,b)     scanL(a), scanL(b)
#define scanL3(a,b,c)   scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define Read            freopen("input.txt", "r" ,stdin)
#define Write           freopen("output.txt", "w" ,stdout)


int ara[N];
int tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return ;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    tree[node]=tree[right]*tree[left];
}
void update(int node,int b,int e,int pos,int val) {
    if(pos>e||pos<b) return;
    if(b==e&&pos==b) {
        tree[node]=val;
        return;
    }
    int left=(2*node); int right=(2*node+1); int mid=(b+e)/2;
    update(left,b,mid,pos,val); update(right,mid+1,e,pos,val);
    tree[node]=tree[left]*tree[right];
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 1;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j); int p2=query(right,mid+1,e,i,j);
    return (p1*p2);
}
int main(int argc,char const *argv[]) {
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF) {
        for(int i=1;i<=n;i++) {
            int val;
            scanf("%d",&val);
            if(val>0) ara[i]=1;
            else if(val<0) ara[i]=-1;
            else ara[i]=0;
        }
        build(1,1,n);
        string ans="";
        for(int i=1;i<=q;i++) {
            string str; cin>>str;
            char ch=str[0]; int pos,val,l,r;
            switch(ch) {
                case 'C': scanf("%d%d",&pos,&val);
                if(val>0) val=1;
                else if(val<0) val=-1;
                else val=0;
                update(1,1,n,pos,val);
                break;
                case 'P': scanf("%d%d",&l,&r);
                int res=query(1,1,n,l,r);
                if(res==1) ans+='+';
                else if(res==-1) ans+='-';
                else ans+='0';
                break;
            }
        }
        cout<<ans<<endl;
        memset(tree,0,sizeof(tree));
    }
    return 0;
}


