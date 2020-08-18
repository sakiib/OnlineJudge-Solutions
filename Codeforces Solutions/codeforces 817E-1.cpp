#include <bits/stdc++.h>


#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,cur) N=(N|(1LL<<cur))
#define Reset(N,cur) N=(N&(~(1LL<<cur)))
#define Check(N,cur) (!((N&(1<<cur))==0))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
//Imran addition
#define rep(i,n) for(int i = 1; i <= n; i++)
#define mem CLR
#define pf printf
#define sc scanf
#define endl "\n"
#define gi(k) scanf("%d",&k)
#define gl(k) scanf("%lld",&k)
#define NMAX 2147483647
#define LMAX 9223372036854775807LL

using namespace std;


#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}


const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

struct node {
    int cnt;
    int child[2];
};

int globalcnt;
node ar[4000006];

void init(int x) {
    ar[x].cnt = 0;
    ar[x].child[0] = ar[x].child[1] = -1;
}

void trieInsert(int id, int pos, int num) {

    ar[id].cnt++;
    if(pos < 0) return;

    int x = Check(num,pos);

    if(ar[id].child[x] == -1) {
        ar[id].child[x] = ++globalcnt;
        init(globalcnt);
    }

    trieInsert(ar[id].child[x], pos-1, num);
}

void trieRemove(int id, int pos, int num) {

    ar[id].cnt--;
    if(pos < 0) return;

    int x = Check(num,pos);

    trieRemove(ar[id].child[x], pos-1, num);
}

int f(int id, int alreadyless, int x, int y, int pos) {
    if(alreadyless) return ar[id].cnt;

    int lf = 0, ri = 1, tmp;
    int res = 0;

    int xbit = Check(x,pos);
    int ybit = Check(y,pos);


    for(int i = lf; i <= ri; i++) {
        if(ar[id].child[i] != -1) {
            if( (xbit ^ i) > ybit ) continue;

            tmp = 0;
            if( (xbit ^ i) < ybit ) tmp = 1;

            res += f(ar[id].child[i], tmp, x, y, pos-1);
        }
    }

    return res;
}

int main () {

    #ifdef forthright48
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
    #endif

    //dump(ar[1].child[0]);

    init(0);

    int n,cmd,x,y,hbit = 30;
    cin >> n;

    rep(i,n) {
        gi(cmd);

        if(cmd == 1) {
            gi(x);
            trieInsert(0,hbit,x);
            //dump(ar[0].cnt);
        }

        else if(cmd == 2) {
            gi(x);
            trieRemove(0,hbit,x);
            //dump(ar[0].cnt);
        }

        else {
            gi(x); gi(y);

            //dump(ar[5].child[0]);
            //dump(ar[6].cnt);
            pf("%d\n",f(0,0,x,y,hbit));
        }
    }


    return 0;
}
