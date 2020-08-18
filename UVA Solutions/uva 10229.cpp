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

struct Matrix { LL M[ 10 ][ 10 ]; };

Matrix original;
int mod;

struct MatrixExponentiation {

    inline Matrix Init( ) {
        Matrix ret;
        for( int i = 0; i <= 5; i++ ) { for( int j = 0; j <= 5; j++ ) {
        ret.M[i][j] = 0; } } return ret;
    }
    inline Matrix Identity( ) {
        Matrix ret;
        for( int i = 1; i <= 2; i++ ) { for( int j = 1; j <= 2; j++ ) {
        if( i == j ) ret.M[i][j] = 1; else ret.M[i][j] = 0; } } return ret;
    }
    inline void Print( Matrix A , int r , int c ) {
        cout <<"........Printing Matrix............."<<endl;
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

    inline Matrix MatMul( Matrix A , Matrix B ) {
        Matrix temp = Init( );
        for( int i = 1; i <= 2; i++ ) {
            for( int j = 1; j <= 2; j++ ) {
                for( int k = 1; k <= 2; k++ ) {
                    temp.M[i][j] = ( temp.M[i][j]%mod+(A.M[i][k]%mod*B.M[k][j]%mod)%mod)%mod;
                }
            }
        } return temp;
    }
    inline Matrix MatExpo( Matrix A , LL P ) {
        Matrix ret;
        if( P == 1 ) return A;
        ret = MatExpo( A , P/2 );
        if( P&1 ) return MatMul( MatMul( ret , ret ) , original ); return MatMul( ret , ret );
    }
};

MatrixExponentiation mat;


int main( int argc, char const *argv[] ) {
    int n , m;
    while( scanf("%d %d",&n,&m) != EOF ) {
        mod = ( 1 << m );
        if( n == 0 ) { printf("0\n"); continue;}
        if( n == 1 ) { printf("1\n"); continue; }
        original = mat.Init( );
        original.M[1][1] = original.M[1][2] = original.M[2][1] = 1;
        Matrix ret = mat.MatExpo( original , n-1 );
        LL ans = ret.M[1][1]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

