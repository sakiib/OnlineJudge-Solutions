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

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int n , m;
map <int,bool> M;

struct node {
        bool endmark;
        int cnt;
        node* child[2];
        node( ) {
                endmark = false;
                cnt = 0;
                child[0] = nullptr , child[1] = nullptr;
        }
} *root;

void add( int num ) {
        node* cur = root;
        for( int i = 20; i >= 0; i-- ) {
                int id = Check( num , i );
                if( cur -> child[id] == nullptr ) {
                        cur -> child[id] = new node();
                }
                cur = cur -> child[id];
                cur -> cnt++;
        }
}
int MEX( int x ) {
        node* cur = root;
        int res = 0;
        for( int i = 20; i >= 0; i-- ) {
                int id = Check( x , i );
                if( cur == nullptr ) return res;
                if( cur -> child[id] == nullptr ) return res;
                if( cur -> child[id] -> cnt < ( 1 << i ) ) {
                        cur = cur -> child[id];
                }
                else {
                        cur = cur -> child[id^1];
                        res = Set( res , i );
                }
        }
        return res;
}
int main( int argc , char const *argv[] ) {
        root = new node( );
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) {
                int num;
                scanf("%d",&num);
                if( !M[num] ) add( num ) , M[num] = true;
        }
        int Xor = 0;
        for( int i = 1; i <= m; i++ ) {
                int x;
                scanf("%d",&x);
                Xor ^= x;
                int mex = MEX( Xor );
                printf("%d\n",mex);
        }
        return 0;
}






