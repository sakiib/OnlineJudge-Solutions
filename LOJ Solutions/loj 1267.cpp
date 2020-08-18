#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

vector <int> V;
vector <pii> points;
int n , q;
int id;

struct data {
        int idx , lx , ly , ux , uy;
        data( int _idx , int _lx , int _ly , int _ux , int _uy ) {
                idx = _idx;
                lx = _lx;
                ly = _ly;
                ux = _ux;
                uy = _uy;
        }
};

vector <data> query;

void reset( ) {
        points.clear();
        query.clear();
        V.clear();
        id = 0;
}
void Update( int idx , int idy , int val ) {
        int y = idy;
        for( ; idx <= id; idx += ( idx & -idx ) ) {
                idy = y;
                for( ; idy <= id ; idy += ( idy & -idy ) ) {
                        BIT[idx][idy] += val;
                }
        }
}
int Query( int idx , int idy ) {
        int y = idy;
        int sum = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) {
                idy = y;
                for( ; idy > 0 ; idy -= ( idy & -idy ) ) {
                        sum += BIT[idx][idy];
                }
        }
        return sum;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                reset( );
                cin >> n >> q;
                for( int i = 1; i <= n; i++ ) {
                        int x , y;
                        cin >> x >> y;
                        points.push_back( make_pair( x , y ) );
                        V.push_back( x );
                        V.push_back( y );
                }
                for( int i = 1; i <= q; i++ ) {
                        int lx , ly , ux , uy;
                        cin >> lx >> ly >> ux >> uy;
                        query.push_back( data( lx , ly , ux , uy ) );
                        V.push_back( lx );
                        V.push_back( ly );
                        V.push_back( ux );
                        V.push_back( uy );
                }
                Unique( V );
        }
        return 0;
}











