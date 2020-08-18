/********************************
*       Sakib Al-Amin           *
*   North South University      *
********************************/

#include <bits/stdc++.h>

using namespace std;

#define endl               '\n'
#define F                  first
#define S                  second
#define SQ(x)              ((x)*(x))
#define CU(x)              (x)*(x)*(x)
#define pb                 push_back
#define mp                 make_pair
#define N                  puts("NO");
#define Y                  puts("YES");
#define dll                long double
#define ll                 long long int
#define llu                unsigned long long int
#define popcount           __builtin_popcountll
#define rightmost          __builtin_ctzll
#define leftmost(x)        (63-__builtin_clzll((x)))
#define gcd(x,y)           __gcd((x),(y))
#define lcm(x,y)           (x)/__gcd((x),(y))*(y)
#define mx3(a,b,c)         max(a,max(b,c))
#define mn3(a,b,c)         min(a,min(b,c))
#define mx4(a,b,c,d)       max(a,mx3(b,c,d))
#define mn4(a,b,c,d)       min(a,mn3(b,c,d))
#define mx5(a,b,c,d,e)     max(a,mx4(b,c,d,e))
#define mn5(a,b,c,d,e)     min(a,mn4(b,c,d,e))
#define mxe(a,n)           (*max_element(a,a+n))
#define mne(a,n)           (*min_element(a,a+n))
#define sum(a,n)           (accumulate(a,a+n,0))
#define CLR(a)             memset(a,0,sizeof(a))
#define SET(a)             memset(a,-1,sizeof(a))
#define all(a)             (a.begin(),a.end())
#define rall(a)            (a.rbegin(),a.rend())
#define Found(a,b)         (a.find(b)!=a.end())
#define Founds(x,y)        (x.find(y)!=string::npos)
#define UB(a,key)          upper_bound(a.begin(),a.end(),key)-a.begin()
#define LB(a,key)          lower_bound(a.begin(),a.end(),key)-a.begin()
#define p_q(smaller)       priority_queue<int,vector<int>,greater<int> >
#define Read               freopen("input.txt",  "r", stdin)
#define Write              freopen("output.txt", "w", stdout)
#define Fastread           ios_base :: sync_with_stdio(false); cin.tie(0)

int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[] = {1, 0, -1, 1, -1, 1, 0, -1};

const ll INF = 1LL*(1e15);
const ll MOD = 1LL*(1e9+7);
const int Size = 100010;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double PII = 2*acos(0.0);

typedef vector< int >         vi;
typedef vector< ll >          vl;
typedef vector< string >      vs;
typedef vector< char >        vc;
typedef set< int >            si;
typedef set< char >           sc;
typedef set< string >         ss;
typedef pair< int,int >       pii;
typedef pair< string,int >    psi;
typedef pair< string,string > pss;
typedef map< int,int >        mii;
typedef map< string,int >     msi;
typedef map< char,int >       mci;
typedef map< string,string >  mss;
typedef map< char,char >      mcc;
typedef queue< int >          qi;
typedef stack< int >          sti;
typedef priority_queue< int > pqi;

inline bool isp(int x) {
    if(x<2) return false;  int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {if(x%i==0) return false;} return true;
}
inline bool leap_year(int x) {
    if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true; return false;
}
inline int power(int x,int y) {
    int ret=1; for(int i=1;i<=y;i++) { ret*=x; }  return ret;
}
inline int st_int(string &str) {
    int num; stringstream st(str); st>>num; return num;
}
inline string int_st(int num) {
    string res; stringstream convert; convert<<num; res=convert.str(); return res;
}

vector<bool> isprime(100010,true);
vector<int> prime;
void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=100010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(100010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=100010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=100010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
    for(auto &x: prime) {
        cout<<x<< " ";
    }
}
//---------------------Let's Code----------------------


int main(int argc,char const *argv[]) {
    Fastread;
    int n,k;
    cin>>n>>k;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int give=0,left=0;
    bool found=false;
    int i=0;
    for(i=1;i<=n;i++) {
        int tot=ara[i]+left;
        if(tot>8) {
            left=tot-8;
            give+=8;
        }
        else {
            give+=tot;
            left=0;
        }
        if(give>=k) {
            found=true;
            break;
        }
    }
    if(found) cout<<i<<endl;
    else cout<<-1<<endl;
    return 0;
}

