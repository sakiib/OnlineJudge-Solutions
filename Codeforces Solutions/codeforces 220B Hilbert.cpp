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

/**
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};*/

const int block = 350;

int n , q;
int ans[ N ];
int l = 1 , r = 0 , res = 0;
int a[ N ];
unordered_map <int,int> cnt;

inline int64_t HilbertOrder( int x, int y, int pow, int rotate ) {
        if (pow == 0) return 0;
        int hpow = 1 << (pow-1);
        int seg = ( x < hpow ) ? ( ( y < hpow ) ? 0 : 3 ) : ( ( y < hpow ) ? 1 : 2 );
        seg = ( seg + rotate ) & 3;
        const int rotateDelta[4] = { 3, 0, 0, 1 };
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = ( rotate + rotateDelta[seg] ) & 3;
        int64_t subSquareSize = int64_t(1) << (2*pow - 2);
        int64_t ans = seg * subSquareSize;
        int64_t add = HilbertOrder(nx, ny, pow-1, nrot);
        ans += ( seg == 1 || seg == 2 ) ? add : ( subSquareSize - add - 1 );
        return ans;
}
struct data {
        int l , r , k , idx;
        int64_t ord;
        data(){}
        data( int l , int r , int k , int idx , int64_t ord ):l(l), r(r), k(k), idx(idx) , ord( ord ){}
        bool operator <( const data &q ) const {
                //int block_a = l / block;
                //int block_b = q.l / block;
                //if( block_a == block_b ) return ( r < q.r );
                //return ( block_a < block_b );
                return ord < q.ord;
        }
} Q[ N ];

void Add( int idx ) {
        if( cnt[a[idx]] == a[idx] ) res--;
        cnt[a[idx]]++;
        if( cnt[a[idx]] == a[idx] ) res++;
}
void Remove( int idx ) {
        if( cnt[a[idx]] == a[idx] ) res--;
        cnt[a[idx]]--;
        if( cnt[a[idx]] == a[idx] ) res++;
}
void MO( ) {
        sort( Q+1 , Q+q+1 );
        for( int i = 1; i <= q; i++ ) {
                while( l < Q[i].l ) Remove( l++ );
                while( l > Q[i].l ) Add( --l );
                while( r < Q[i].r ) Add( ++r );
                while( r > Q[i].r ) Remove( r-- );
                ans[ Q[i].idx ] = res;
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= q; i++ ) {
                scanf("%d %d",&Q[i].l,&Q[i].r);
                Q[i].idx = i;
        }
        for( int i = 1; i <= q; i++ ) Q[i].ord = HilbertOrder( Q[i].l , Q[i].r , 21 , 0 );
        MO( );
        for( int i = 1; i <= q; i++ ) printf("%d\n",ans[i]);
        return 0;
}








