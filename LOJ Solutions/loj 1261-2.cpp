#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n , m , k;
vector <int> pos[ N ];
vector <int> neg[ N ];
int sol[ N ];
set <int> S;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&m,&k);
                for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= k; j++ ) {
                                int val;
                                scanf("%d",&val);
                                if( val > 0 ) pos[i].push_back( val );
                                else neg[i].push_back( abs(val) );
                        }
                }
                int p;
                scanf("%d",&p);
                for( int i = 1; i <= p; i++ ) scanf("%d",&sol[i]) , S.insert( sol[i] );
                bool happy = false;
                for( int i = 1; i <= n; i++ ) {
                        happy = false;
                        for( int j = 0; j < pos[i].size(); j++ ) {
                                if( S.find( pos[i][j] ) != S.end() ) {
                                        happy = true;
                                        break;
                                }
                        }
                        for( int j = 0; j < neg[i].size(); j++ ) {
                                if( S.find( neg[i][j] ) == S.end() ) {
                                        happy = true;
                                        break;
                                }
                        }
                        if( !happy ) break;
                }
                if( happy ) printf("Case %d: Yes\n",tc);
                else printf("Case %d: No\n",tc);
                S.clear();
                for( int i = 1; i < N; i++ ) pos[i].clear() , neg[i].clear();
        }
        return 0;
}






