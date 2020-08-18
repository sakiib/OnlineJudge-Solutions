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

Matrix ori;
LL mod;

struct MatrixExponentiation {

    inline Matrix Init( ) {
        Matrix ret;
        for( int i = 0; i <= 10; i++ ) { for( int j = 0; j <= 10; j++ ) {
        ret.M[i][j] = 0; } } return ret;
    }
    inline Matrix Identity( ) {
        Matrix ret;
        for( int i = 1; i <= 10; i++ ) { for( int j = 1; j <= 10; j++ ) {
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
        for( int i = 1; i <= 10; i++ ) { for( int j = 1; j <= 10; j++ ) {
        ret.M[i][j] = A.M[i][j] + B.M[i][j]; }  } return ret;
    }
    inline Matrix MatSub( Matrix A , Matrix B ) {
        Matrix ret;
        for( int i = 1; i <= 10; i++ ) { for( int j = 1; j <= 10; j++ ) {
        ret.M[i][j] = A.M[i][j] - B.M[i][j]; }  } return ret;
    }

    inline Matrix MatMul( Matrix A , Matrix B ) {
        Matrix temp = Init( );
        for( int i = 1; i <= 6; i++ ) {
            for( int j = 1; j <= 6; j++ ) {
                for( int k = 1; k <= 6; k++ ) {
                    temp.M[i][j] = ( temp.M[i][j]%mod+( A.M[i][k]%mod*B.M[k][j]%mod)%mod ) %mod;
                }
            }
        } return temp;
    }
    inline Matrix MatExpo( Matrix A , LL P ) {
        Matrix ret;
        if( P == 1 ) return A;
        ret = MatExpo( A , P/2 );
        if( P&1 ) return MatMul( MatMul( ret , ret ) , ori ); return MatMul( ret , ret );
    }
};

MatrixExponentiation mat;

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL a1 , b1 , c1;
        scanf("%lld %lld %lld",&a1,&b1,&c1);
        LL a2 , b2 , c2;
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        LL f0 , f1 , f2;
        scanf("%lld %lld %lld",&f0,&f1,&f2);
        LL g0 , g1 , g2;
        scanf("%lld %lld %lld",&g0,&g1,&g2);
        scanf("%lld",&mod);
        ori = mat.Init( );
        ori.M[1][1] = a1%mod , ori.M[1][2] = b1%mod , ori.M[1][6] = c1%mod;
        ori.M[2][1] = 1;
        ori.M[3][2] = 1;
        ori.M[4][3] = c2%mod , ori.M[4][4] = a2%mod , ori.M[4][5] = b2%mod;
        ori.M[5][4] = 1;
        ori.M[6][5] = 1;
        printf("Case %d:\n",tc);
        int q;
        scanf("%d",&q);
        while( q-- ) {
            LL n;
            scanf("%lld",&n);
            if( n == 0 ) {
                printf("%lld %lld\n",f0%mod,g0%mod);
            }
            else if( n == 1 ) {
                printf("%lld %lld\n",f1%mod,g1%mod);
            }
            else if( n == 2 ) {
                printf("%lld %lld\n",f2%mod,g2%mod);
            }
            else {
                Matrix res = mat.MatExpo( ori , n-2 );
                LL a = ( (res.M[1][1]%mod*f2%mod)%mod + (res.M[1][2]%mod*f1%mod)%mod +
                        (res.M[1][3]%mod*f0%mod)%mod + (res.M[1][4]%mod*g2%mod)%mod +
                        (res.M[1][5]%mod*g1%mod)%mod + (res.M[1][6]%mod*g0%mod)%mod )%mod;

                LL b = ( (res.M[4][1]%mod*f2%mod)%mod + (res.M[4][2]%mod*f1%mod)%mod +
                        (res.M[4][3]%mod*f0%mod)%mod + (res.M[4][4]%mod*g2%mod)%mod +
                        (res.M[4][5]%mod*g1%mod)%mod + (res.M[4][6]%mod*g0%mod)%mod )%mod;
                printf("%lld %lld\n",a,b);
            }
        }
    }
    return 0;
}

