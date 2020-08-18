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

bool visited[ N ];
int n;
vector <string> ans;

void dfs( int val , string &s ) {
    if( val == 0 ) {
        ans.push_back( s );
        return;
    }
    if( s.size() > 10 ) return;
    string a = s+"0";
    string b = s+"1";
    dfs( (val%n*10%n)%n , a );
    dfs( (val%n*10%n+1%n)%n , b );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&n);
        string temp = "1";
        dfs( 1 , temp );
        sort( ans.begin() , ans.end() );
        for( auto x : ans ) cout << x <<endl;
    }
    return 0;
}

