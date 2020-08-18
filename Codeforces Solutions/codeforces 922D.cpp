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
#define All(V)      V.begin(),V.end()
#define SORT(V)     sort( V.begin(), V.end() )
#define REV(V)      sort( V.rbegin(), V.rend() )
#define MEM(a,x)    memset( a, x, sizeof(a) )
#define FOR(i,a,b)  for( int i = a; i <= b; i++ )
#define ROF(i,a,b)  for( int i = b; i >= a; i-- )
#define REP(i,a)    for( int i = 0; i < a; i++ )
#define debug(x)    cerr << "The value is "<< x << endl
#define Unique(V)   sort( All(a)), a.erase( unique( All(a) ), a.end())
#define UB(a,key)   upper_bound( a.begin(), a.end(), key )-a.begin()
#define LB(a,key)   lower_bound( a.begin(), a.end(), key )-a.begin()

vector <string> V;

LL calc( string s ) {
    LL cnt = 0 , ans = 0;
    FOR( i , 0 , s.size()-1 ) {
        if( s[i] == 's' ) cnt++;
        else ans += cnt;
    }
    return ans;
}
bool cmp( string &a , string &b ) {
    // cout << a << " " << b << endl;
    string x = a+b;
    string y = b+a;
    return ( calc(x) > calc(y) );
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    string str;
    FOR( i , 1 , n ) cin >> str , V.pb( str );
    sort( V.begin() , V.end() , cmp );
    string res = "";
    FOR( i , 0 , V.size()-1 ) res += V[i];
    LL x = calc( res );
    printf("%lld\n",x);
    return 0;
}


