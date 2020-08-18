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

int ara[ N ];
vector < int > pos[ N ];

void go( int num , int id ) {
    int sq = sqrt( num );
    for( int i = 1; i <= sq; i++ ) {
        if( num%i == 0 ) {
           pos[i].push_back( id );
           if( num/i != i ) pos[num/i].push_back( id );
        }
    }
}
int LB( int l , int r , int k ) {
    int ret = lower_bound( pos[k].begin() , pos[k].end() , l )-pos[k].begin();
    return ret;
}
int UB( int l , int r , int k ) {
    int ret = upper_bound( pos[k].begin() , pos[k].end() , r )-pos[k].begin();
    return ret;
}
int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
        go( ara[i] , i );
    }
    /*
    for( int i = 1; i <= 5; i++ ) {
        for( int j = 0; j < pos[i].size(); j++ ) {
            cout << pos[i][j] << " ";
        }
        cout << endl;
    }*/
    while( q-- ) {
        int l , r , k;
        scanf("%d %d %d",&l,&r,&k);
        int ub = UB( l , r , k );
        int lb = LB( l , r , k );
        printf("%d\n",(ub-lb));
    }
    return 0;
}

