///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // Include for built in treap
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//#include <sys/resource.h>     // for linux stack memory increase
//#define gc getchar_unlocked   // for linux fast io
//#define gc getchar            // for windows fast io

#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define nl puts("")
#define sp printf(" ")
#define phl debug("Hello")
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((vlong)(x).size())
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define SQ(x) ((x)*(x))
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,p) N=((N)|((1LL)<<(p)))
#define Reset(N,p) N=((N)&(~((1LL)<<(p))))
#define Check(N,p) (!(((N)&((1LL)<<(p)))==(0)))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define arrayIndexPrint(A,i) cerr<<"~ At pos: "<<i<<" = "<<A[i]
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
#define arrayPrint(A,st,ed) cerr<<"~ Array:";FOR(i,st,ed) cerr<<" "<<A[i];cerr<<endl
#define LINE cerr<<"\n"; FOR(i,0,50) cerr<<"=";cerr<<"\n\n"

#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;
//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1; /// For bigmod2 multiply here using mulmod
    }
    return res;
}


//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//int dir8[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{1,-1},{-1,1}};
const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-11;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// For generating random numbers

///======================  TEMPLATE ENDS HERE  =====================///


inline int add( int x , int y , int mod ) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub( int x , int y , int mod ) {
    return x - y < 0 ? x - y + mod : x - y;
}
inline int mul( int x , int y , int mod ) {
    return ( 1LL * x * y ) % mod;
}
struct hashing {
    const int N = 200005;
    const int mod[2] = { 1000000007, 1000000009 };
    const int base[2] = { 43 , 37 };
    const int invbase[2] = { 395348840 , 297297300 };
    vector < vector <int> > p;
    vector < vector <int> > invmod;
    vector < vector <int> > fh;
    vector < vector <int> > bh; int tlen;
    inline void gen_pow( int sz ) {
        p.resize( sz + 2 );
        invmod.resize( sz + 2 );
        for( int i = 0; i <= sz; i++ ) p[i].resize( 2 ), invmod[i].resize( 2 );
        p[0][0] = 1 , p[0][1] = 1 , invmod[0][0] = 1 , invmod[0][1] = 1;
        for( int i = 1; i <= sz; i++ ) {
            for( int id = 0; id <= 1; id++ ) {
                p[i][id] = mul( p[i-1][id] , base[id] , mod[id] );
                invmod[i][id] = mul( invmod[i-1][id] , invbase[id] , mod[id] );
            }
        }
    }
    inline void build_hash( string &txt ) {
        tlen = txt.size();
        fh.resize( tlen + 2 );
        bh.resize( tlen + 2 );
        for( int i = 0; i <= tlen; i++ ) fh[i].resize( 2 ), bh[i].resize( 2 );
        for( int i = 0 , j = tlen - 1; i < tlen; i++ , j-- ) {
            for( int id = 0; id <= 1; id++ ) {
                fh[i][id] = mul( p[i][id] , txt[i] , mod[id] );
                if( i ) fh[i][id] = add( fh[i][id] , fh[i-1][id] , mod[id] );
                bh[i][id] = mul( p[j][id] , txt[i] , mod[id] );
                if( i ) bh[i][id] = add( bh[i][id] , bh[i-1][id] , mod[id] );
            }
        }
    }
    inline LL combine_hash( LL x , LL y ) { return ( x << 31 ) | y; }
    inline LL get_fhash( int l , int r ) {
        if( l == 0 ) return combine_hash( fh[r][0] , fh[r][1] );
        int x = sub( fh[r][0], fh[l-1][0], mod[0] );
        x = mul( x, invmod[l][0], mod[0] );
        int y = sub( fh[r][1], fh[l-1][1], mod[1] );
        y = mul( y, invmod[l][1], mod[1] ); return combine_hash( x , y );
    }
} H1, H2;


string str1, str2;
int N;

int call(int a1, int a2, int b1, int b2) {
    if(H1.get_fhash(a1, a2)==H2.get_fhash(b1, b2)) {
        return true;
    }

    int len = (a2-a1+1);

    if( len % 2 != 0 ) {
        return false;
    }

    return (call(a1, a1+(len/2)-1, b1,  b1+(len/2)-1) && call(a1+(len/2), a2, b1+(len/2), b2))
        || (call(a1, a1+(len/2)-1, b1+(len/2), b2) &&  call(a1+(len/2), a2, b1,  b1+(len/2)-1));

}

int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    fast_cin;

    cin >> str1 >> str2;
    H1.gen_pow(str1.size());
    H2.gen_pow(str2.size());
    H1.build_hash(str1);
    H2.build_hash(str2);

    N = str1.size();

    if(call(0, N-1, 0, N-1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
