#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

vector <LL> get_div( LL x , LL f ) {
        vector <LL> ret;
        LL sq = sqrt( x );
        for( LL i = 1; i <= sq; i++ ) {
                if( x%i == 0 ) {
                       if( i > f ) ret.push_back( i );
                       if( x/i != i && x/i > f ) {
                            ret.push_back( x/i );
                       }
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        //ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL P , L;
                scanf("%lld %lld",&P,&L);
                P -= L;
                vector <LL> V = get_div( P , L );
                if( V.size() == 0 ) printf("Case %d: impossible\n",tc);
                else {
                        sort( V.begin() , V.end() );
                        printf("Case %d: ",tc);
                        for( int i = 0; i < V.size(); i++ ) {
                                if( i == 0 ) printf("%lld",V[i]);
                                else printf(" %lld",V[i]);
                        }
                        printf("\n");
                }
        }
        return 0;
}






