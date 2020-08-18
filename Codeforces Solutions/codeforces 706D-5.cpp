#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
#define ii                       pair < int, int >
#define iii                      pair < int, ii >
#define FOR( i, a, b )           for( int i = a; i <= b; i++ )
#define ROF( i, a, b )           for( int i = a; i >= b; i-- )
#define pb                       push_back
#define mp                       make_pair
#define line                     cerr << "***** here *****" << endl;
#define all( V )                 V.begin(), V.end()
#define Unique( a )              sort(all(a)),a.erase(unique(all(a)),a.end())
#define sc                       scanf
#define pf                       printf
#define Fix( x )                 setprecision( x ) << fixed
#define mem( a, x )              memset( a, x, sizeof( a ) )

bool Check( int N , int pos ) { return (bool)( N & ( 1 << pos ) ); }

struct Node {
    bool Endmark;
    int cnt;
    int val;
    Node* Child[ 2 ];
    Node( ) {
        Endmark = false;
        cnt = 0;
        val = 0;
        Child[0] = Child[1] = NULL;
    }
} *Root;

void Add( int n ) {
    Node* cur = Root;
    for( int i = 31; i >= 0; i-- ) {
        bool id = Check( n , i );
        if( cur -> Child[id] == NULL ) cur -> Child[id] = new Node();
        cur = cur -> Child[id];
        cur -> cnt++;
    }
    cur -> val = n;
}
void Erase( int n ) {
    Node* cur = Root;
    for( int i = 31; i >= 0; i-- ) {
        bool id = Check( n , i );
        cur = cur -> Child[id];
        cur -> cnt--;
    }
}
int MaxXOR( int n ) {
    Node* cur = Root;
    for( int i = 31; i >= 0; i-- ) {
        bool id = Check( n , i );
        if( cur -> Child[1-id] != NULL && (cur -> Child[1-id] -> cnt) > 0 ) {
           cur = cur -> Child[1-id];
        }
        else if( cur -> Child[id] != NULL ) {
           cur = cur -> Child[id];
        }
        cur -> cnt--;
    }
    return ( n^( cur -> val ) );
}
int main( int argc, char const *argv[] ) {

    Root = new Node( );

    Add( 0 );

    int n;
    cin >> n;
    while( n-- ) {
        string s;
        int num;
        cin >> s >> num;
        if( s[0] == '+' ) Add( num );
        else if( s[0] == '-' ) Erase( num );
        else cout << MaxXOR( num ) << endl;
    }
    return 0;
}






