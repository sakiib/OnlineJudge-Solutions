#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 3*1e3 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , m;
vector <LL> party[ N ];
int cnt[ N ] , tcnt[ N ];
multiset <LL> S;

LL check( int vote ) {
        for( int i = 1; i <= m; i++ ) tcnt[i] = cnt[i];
        multiset <LL> tS = S;
        //printf("Vote : %d\n",vote);
        int bribe = 0;
        LL cost = 0;
        for( int i = 2; i <= m; i++ ) {
                int cur = (int)party[i].size();
                for( int j = 0; j < party[i].size() && cur >= vote+bribe ; j++ ) {
                        if( cnt[1] + bribe >= vote ) break;
                        bribe++;
                        cost += party[i][j];
                        cur--;
                        tcnt[i]--;
                        tS.erase( tS.find( party[i][j] ) );
                }
        }
        //printf("Bribe : %d\n",bribe);
        for( int i = 2; i <= m; i++ ) {
                int j;
                if( party[i].size() >= vote ) j = vote - 1;
                else j = 0;
                for( ; j < party[i].size(); j++ ) {

                }
        }
        for( int i = 2; i <= m; i++ ) if( tcnt[i] >= vote ) return INF;
        //printf("xBribe : %d\n",bribe);
        return ( cnt[1] + bribe >= vote ? cost : INF );
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) {
                int id;
                LL c;
                scanf("%d %lld",&id,&c);
                if( id != 1 ) S.insert( c );
                cnt[id]++ , party[id].push_back( c );
        }
        for( int i = 1; i <= m; i++ ) sort( party[i].begin(), party[i].end() );
        bool f = true;
        for( int i = 2; i <= m; i++ ) if( cnt[i] >= cnt[1] ) f = false;
        if( f ) return printf("0\n"),0;
        LL ans = INF;
        for( int i = 1; i <= m; i++ ) {
                ans = min( ans , check( i ) );
                //cout << "here : " << i << " "<< check( i ) << endl;
        }
        printf("%lld\n",ans);
        return 0;
}






