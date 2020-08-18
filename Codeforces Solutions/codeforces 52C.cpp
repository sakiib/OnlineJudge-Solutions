#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long int LL;
typedef unsigned long long uLL;

const int inf=1e9;
const LL INF=1e18;
const int N=100005;
const int MOD=1e9+7;

#define PI     acos(-1.0)
#define EPS    1e-9
#define ff     first
#define ss     second
#define pb     push_back
#define mp     pake_pair
#define pp     pop_back
#define SQ(x) ((x)*(x))
#define CU(x) (x)*(x)*(x)
#define pii    pair<int,int>
#define piii   pair<int,ii>
#define PQ(x)  priority_queue<x,vector<x>,greater<x> >

#define clr(V)   V.clear()
#define All(V)   V.begin(),V.end()
#define SORT(V)  sort(V.begin(),V.end())
#define REV(V)   sort(V.rbegin(),V.rend())
#define MEM(a,x) memset(a,x,sizeof(a))
#define CLR(a,n) for(int i=0;i<n;i++) a[i].clear()

#define POPCOUNT  __builtin_popcountll
#define RIGHTMOST  __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))

#define debug(x)  cerr<<"X is : "<<x<<endl
#define here  cerr<<"here : <===========>"<<endl

#define Found(a,b) a.find(b) != a.end()
#define Unique(a)  sort(all(a)),a.erase(unique(all(a)),a.end())
#define UB(a,key)  upper_bound(a.begin(),a.end(),key)-a.begin()
#define LB(a,key)  lower_bound(a.begin(),a.end(),key)-a.begin()
#define DIST(x1,y1,x2,y2) sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=b;i>=a;i--)
#define REP(i,a)   for(int i=0;i<a;i++)

#define Read   freopen("input.txt","r",stdin)
#define Write  freopen("output.txt","w",stdout)

int dx4[] = {+1, -1, +0, +0};
int dy4[] = {+0, +0, +1, -1};
int dx8[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int dy8[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthL[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

///------------------------------------------------------------------------------------------------------------------
/// Policy Based Data Structure
/*
template<typename T>
using orderset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
*/
// declaration -> orderset<int> St;
// St.insert(val), St.erase(val), St.order_of_key(val), *St.find_by_order(val-1)
// St.find_by_order(val-1) == st.end() -> Invalid...

inline LL GCD (LL a,LL b) {a=abs(a); b=abs(b); while (b) {a=a%b; swap(a,b);} return a;}
inline LL LCM (LL a,LL b) {a=abs(a); b=abs(b); LL g=GCD(a,b); return a*b/g;}
inline LL Power (LL a,LL p) {LL res=1,x=a; while(p) {if(p&1) res=(res*x); x=(x*x); p>>=1;} return res;}
inline LL BigMod (LL a,LL p,LL m) {LL res=1%m,x=a%m; while(p) {if(p&1) res=(res*x)%m; x=(x*x)%m; p>>=1;} return res;}
inline bool IsLeap (int x) {if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true; return false;}
inline bool IsPrime (int x) {if(x<2) return false;  int sq=sqrt(x);for(int i=2;i<=sq;i++) {if(x%i==0) return false;} return true;}
inline int String_Int (string &str) {int num; stringstream st(str); st>>num; return num;}
inline string Int_String (int num) {string res; stringstream convert; convert<<num; res=convert.str(); return res;}
inline bool String_Mod (string &s,int m) {int res=0;for(int i=0;i<s.size();i++) {res=((res%m*10%m)%m+(s[i]-'0')%m)%m;}if(res==0) return true;else return false;}
inline LL FindTrailingZeros (LL n){LL cnt=0; for(LL i=5;n/i>=1;i*=5) cnt+= n/i; return cnt;}
inline LL NumDigit (LL x,LL y) {return ((LL)(log10((x))/log10((y))))+1;}

///Sieve prime upto 1e7(long long)
/*
vector<LL> prime; vector<bool> isprime(10000010,true);
inline void sieve() {isprime[0]=false,isprime[1]=false; prime.push_back(2);for(LL i=4;i<=10000010;i+=2) {isprime[i]=false;}
LL sq=sqrt(10000010); for(LL i=3;i<=sq;i+=2) {if(isprime[i]) {for(LL j=i*i;j<=10000010;j+=2*i) {isprime[j]=false;}}}
for(LL i=3;i<=10000010;i+=2) {if(isprime[i]) prime.push_back(i);}}
*/
///Number of Divisor(Loop)
/*
LL nod[1000005];
inline void NOD() {for(LL i=1;i<=1000000;i++) {for(LL j=i;j<=1000000;j+=i) {nod[j]++;}}}
*/
///Number of Divisor using primefactorization
//inline LL NOD(LL n) {LL sq=sqrt(n);LL ret=1LL;for(int i=0;i<prime.size()&&prime[i]<=sq;i++) {if(n%prime[i]==0) {LL p=0;while(n%prime[i]==0) {n/=prime[i];p++;} sq=sqrt(n);p++;ret*=p;}}if(n!=1) ret*=2;return ret;}
///Sum of Divisor(Loop)
/*
LL sod[1000005];
inline void SOD(){for(LL i=1; i<=1000000; i++) {for(LL j=i; j<=1000000; j+=i){sod[j] += i;}}}
*/
///Sum of Divisor using primefactorizaton
/*
inline LL SOD(LL n) {LL res = 1;LL sqrtn=sqrt(n);for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++) {if(n%prime[i]==0) {LL tempSum = 1; LL p = 1; while(n%prime[i]==0) {n/=prime[i];p *= prime[i];tempSum += p;}sqrtn = sqrt ( n );res *= tempSum;}}if ( n != 1 ) {res *= ( n + 1 ); }return res;}
*/
///Loop PHI
/*
inline LL Loop_Phi(LL n) { LL ans=n;for(LL i=2;i*i<=n;i++) {if(n%i==0) {ans-=(ans/i);}while(n%i==0) {n/=i;}}if(n>1) ans-=(ans/n);return ans;}
*/
///Sieve PHI
/*
inline LL Sieve_Phi(LL x) { vector<LL> val;LL temp=x;LL vag=1;for(int i=0;i<prime.size();i++) {if(x%prime[i]==0) {vag*=prime[i];val.push_back(prime[i]);x/=prime[i];while(x%prime[i]==0) {x/=prime[i];}}}if(x>1) val.push_back(x),vag*=x;for(int i=0;i<val.size();i++) {temp*=(val[i]-1);}temp/=vag; return temp;}
*/
///PHI for all numbers in a Range(1 to 1e6)
/*
LL phi[1000010]; LL mark[1000010];
inline void Sieve_Phi_All() {for(LL i=1;i<=1000000;i++) phi[i]=i;phi[1]=1; mark[1]=1;for(LL i=2;i<=1000000;i++) {if(!mark[i]) {for(LL j=i;j<=1000000;j+=i) {mark[j]=1;phi[j]=phi[j]/i*(i-1);}}}}
*/
///*************************************************************************************************************************************
///*************************************************************************************************************************************


LL ara[2*N];
LL tree[8*N],lazy[8*N];

void build(LL node,LL b,LL e){
    if(b>e) return;
    if(b==e) {
        tree[node]=ara[b];
        lazy[node]=0;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
    lazy[node]=lazy[left]+lazy[right];
}
void propagate(LL node,LL b,LL e) {
    if(lazy[node]!=0) {
        tree[node]+=lazy[node];
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void update(LL node,LL b,LL e,LL i,LL j,LL val) {

    propagate(node,b,e);

    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        tree[node]+=val;
        if(b!=e) {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node]=min(tree[left],tree[right]);
}
LL query(LL node,LL b,LL e,LL i,LL j) {

    propagate(node,b,e);

    if(i>e||j<b) return INF;
    if(i<=b&&j>=e) return tree[node];
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    return min(query(left,b,mid,i,j),query(right,mid+1,e,i,j));
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    build(1,1,n);
    LL m;
    scanf("%lld",&m);
    for(int i=1;i<=m;i++) {
        LL a,b;
        char c;
        scanf("%lld %lld%c",&a,&b,&c);
        a++,b++;
        if(c!='\n') {
            LL val;
            scanf("%lld",&val);
            if(a>b) {
                update(1,1,n,a,n,val);
                update(1,1,n,1,b,val);
            }
            else update(1,1,n,a,b,val);
        }
        else {
            if(a>b) {
                LL ans=min(query(1,1,n,a,n),query(1,1,n,1,b));
                printf("%lld\n",ans);
            }
            else printf("%lld\n",query(1,1,n,a,b));
        }
    }
    return 0;
}


