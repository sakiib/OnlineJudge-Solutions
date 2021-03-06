/***********Template Starts Here***********/
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
#define NORM(x) if(x>=mod)x-=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < vlong, vlong > pll;
typedef vector<pll> vll;
typedef vector<vlong> vl;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

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

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

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
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/

int arr[1000010];

struct node {
    int mn, mx;
}tnode[4000010];

void build ( int t, int b, int e ) {
    int mid = ( b + e ) / 2;
    int u = mid * 2;
    int v = u + 1;

    if ( b == e ) {
        tnode[t].mn = b;
        tnode[t].mx = b;
        return;
    }

    build ( u, b, mid );
    build ( v, mid + 1, e );

    tnode[t].mn = arr[tnode[u].mn] < arr[tnode[v].mn]? tnode[u].mn: tnode[v].mn;
    tnode[t].mx = arr[tnode[u].mx] > arr[tnode[v].mx]? tnode[u].mx: tnode[v].mx;
}

int qb, qe, qmn, qmx;
void query ( int t, int b, int e ) {
    int mid = ( b + e ) / 2;
    int u = mid * 2;
    int v = u + 1;

    if ( qb <= b && e <= qe ) {
        qmn = arr[qmn] < arr[tnode[t].mn]? qmn: tnode[t].mn;
        qmx = arr[qmx] > arr[tnode[t].mx]? qmx: tnode[t].mx;
        return;
    }
    if ( qe < b || e < qb ) {
        return;
    }

    query ( u, b, mid );
    query ( v, mid + 1, e );
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    int n, m;
    scanf ( "%d %d", &n, &m );

    FOR(i,1,n) {
        scanf ( "%d", &arr[i] );
    }

    build ( 1, 1, n );

    while ( m-- ) {
        int l, r, x;
        scanf ( "%d %d %d", &l, &r, &x );

        qb = l; qe = r; qmn = l; qmx = l;

        query( 1, 1, n );

        cout << "here : " << qmn << " " << qmx << endl;

        if ( arr[qmn] == x && arr[qmx] == x ) printf ( "-1\n" );
        else if ( arr[qmn] == x ) printf ( "%d\n", qmx );
        else printf ( "%d\n", qmn );
    }

    return 0;
}
