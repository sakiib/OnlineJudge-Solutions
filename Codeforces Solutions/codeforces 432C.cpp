/***********Template Starts Here***********/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define popcount __builtin_popcount
#define rightmost __builtin_ctz

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef vector < int > vi;
typedef pair < int, int > ii;
typedef pair < vlong, vlong > lili;
typedef vector < ii > vii;

template < class T > T sq( T x ) { return x * x; }

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;

/***********Template Ends Here***********/

vi prime;
char stat[100010];

void sieve ( int n ) {

    prime.pb ( 2 );
    int i, j, sqrtn = sqrt ( n );
    for ( i = 3; i <= sqrtn; i+= 2 ) {
        if ( stat[i] == 0 ) {
            for ( j = i * i; j <= n; j += 2 * i ) stat[j] = 1;
        }
    }
    for ( i = 3; i <= n; i += 2 ) if ( stat[i] == 0 ) prime.pb ( i );
}

int n;
int arr[100010];
int pos[100010];

vii moves;

void bring ( int p ) {
    int cur = pos[p];

    int m = cur - p + 1;
    if ( m == 1 ) return;
    else {
        int sub = upper_bound ( prime.begin(), prime.end(), m ) - prime.begin();
        //cerr<<sub<<endl; exit(0);
        sub = prime[sub-1];
        //cerr<<arr[cur]<< " "<<arr[cur-sub+1]<<endl; exit(0);
        swap ( arr[cur], arr[cur-sub+1] );
        int a = arr[cur];
        int b = arr[cur-sub+1];
        swap ( pos[a], pos[b] );

        moves.pb ( make_pair ( cur - sub + 1, cur ) );

        bring ( p );
    }
}

int main () {
    sieve ( 100000 );

    //findDif();
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif

    scanf ( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ ) {
        scanf ( "%d", &arr[i] );
        int p = arr[i];
        pos[p] = i;
    }

    for ( i = 1; i <= n; i++ ) {
        bring ( i );
    }

    printf ( "%d\n", moves.size() );
    for ( i = 0; i < moves.size(); i++ ) {
        printf ( "%d %d\n", moves[i].ff, moves[i].ss );
    }

    return 0;
}
