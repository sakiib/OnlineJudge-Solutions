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


struct Matrix { LL M[ 20 ][ 20 ]; };

Matrix Ori;
int mod;

struct MatrixExponentiation {

    inline Matrix Init( ) {
        Matrix ret;
        for( int i = 0; i < 20; i++ ) { for( int j = 0; j < 20; j++ ) {
        ret.M[i][j] = 0; } } return ret;
    }
    inline Matrix Identity( ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        if( i == j ) ret.M[i][j] = 1; else ret.M[i][j] = 0; } } return ret;
    }
    inline void Print( Matrix A , int r , int c ) {
        cout <<"........Printing Matrix.............\n"<<endl;
        for( int i = 1; i <= r; i++ ) { for( int j = 1; j <= c; j++ ) {
        printf("%lld  ",A.M[i][j]); } printf("\n\n"); }
        cout <<"........Done Printing Matrix........"<<endl;
    }
    inline Matrix MatAdd( Matrix A , Matrix B ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        ret.M[i][j] = A.M[i][j] + B.M[i][j]; }  } return ret;
    }
    inline Matrix MatSub( Matrix A , Matrix B ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        ret.M[i][j] = A.M[i][j] - B.M[i][j]; }  } return ret;
    }

    inline Matrix MatMul( Matrix A , Matrix B , int r ) {
        Matrix temp = Init( );
        for( int i = 1; i <= r; i++ ) {
            for( int j = 1; j <= r; j++ ) {
                for( int k = 1; k <= r; k++ ) {
                    temp.M[i][j] = ( temp.M[i][j]%mod+( A.M[i][k]%mod*B.M[k][j]%mod)%mod )%mod;
                }
            }
        } return temp;
    }
    inline Matrix MatExpo( Matrix A , LL P , int r ) {
        Matrix ret;
        if( P == 1 ) return A;
        ret = MatExpo( A , P/2 , r );
        if( P&1 ) return MatMul( MatMul( ret , ret , r ) , Ori , r ); return MatMul( ret , ret , r );
    }
};

MatrixExponentiation mat;

LL b[ 20 ] , c[ 20 ];

int main( int argc, char const *argv[] ) {

        int k , n , m;

        while( scanf("%d %d %d",&k,&n,&m) ) {
        if( !k && !n && !m ) break;
        mod = m;
        for( int i = 1; i <= k; i++ ) scanf("%lld",&c[i]);
        for( int i = 1; i <= k; i++ ) scanf("%lld",&b[i]);
        if( n <= k ) {
            printf("%lld\n",b[n]%mod);
            continue;
        }
        Ori = mat.Init( );
        int r = k;
        for( int i = 1; i <= k; i++ ) Ori.M[1][i] = c[i];
        for( int i = 1; i <= r; i++ ) {
            for( int j = 1; j <= r; j++ ) {
               if( i == j+1 ) Ori.M[i][j] = 1;
            }
        }
        Matrix res = mat.MatExpo( Ori , n-k , k );
        int l = k;
        LL ans = 0;
        for( int i = 1; i <= r; i++ ) ans = ( ans%mod + ( res.M[1][i]%mod*b[l--]%mod )%mod )%mod;
        printf("%lld\n",ans);
        }
        return 0;
}


