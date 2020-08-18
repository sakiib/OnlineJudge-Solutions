#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define mp          pake_pair
#define CLR(V)      V.clear()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )

int m;
LL ans = 0;

bool valid( int x , int y , int z ) {
    if( (x+y) > z && (y+z) > x && (x+z) > y && ( x <= y && y <= z ) )
    return true;
    else return false;
}
void solve( int a , int b ) {
    int x = (a^b);
    if( valid( a , b , x ) && x <= m ) {
        ans++;
    }
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&m);
    FOR( i , 1 , m ) {
        FOR( j , i+1 , m ) {
            solve( i , j );
        }
    }
    printf("%lld\n",ans);
    return 0;
}


