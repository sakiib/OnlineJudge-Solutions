#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int ara[ N ] , h[ N ];
int n;

struct segment {
    int val;
    int id;
} Tree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].val = h[b] , Tree[node].id = b;
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;

    Build( left , b , mid );
    Build( right , mid+1 , e );

    if( Tree[left].val >= Tree[right].val ) {
        Tree[node].val = Tree[left].val;
        Tree[node].id = Tree[left].id;
    }
    else {
        Tree[node].val = Tree[right].val;
        Tree[node].id = Tree[right].id;
    }
}
segment Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e ) return {0,0};
    if( i <= b && j >= e ) return Tree[node];

    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    segment Q1 = {0,0} , Q2 = {0,0} , ret = {0,0};

    Q1 = Query( left , b , mid , i , j );
    Q2 = Query( right , mid+1 , e , i , j );

    if( Q1.val >= Q2.val ) {
        ret.val = max( ret.val , Q1.val ) , ret.id = Q1.id;
    }
    else {
        ret.val = max( ret.val , Q2.val ) , ret.id = Q2.id;
    }
    return ret;
}
void GoLeft( int mxval , int pos , int l ) {
    //cout <<"Left : "<< mxval << " " << pos << " " << l << endl;
    for( int i = pos-1; i >= l; i-- ) {
        if( ara[i] < mxval ) return;
        ara[i] = mxval;
    }
}
void GoRight( int mxval , int pos , int r ) {
    //cout <<"Right : "<< mxval << " " << pos << " " << r << endl;
    for( int i = pos+1; i <= r; i++ ) {
        if( ara[i] < mxval ) return;
        ara[i] = mxval;
    }
}
void solve( ) {

    Build( 1 , 1 , n );

    queue < pair<int, int> > Q;

    Q.push( {1,n} );

    int Ans = 0;

    while( !Q.empty( ) ) {
        pair<int,int> f = Q.front( ); Q.pop();

        int l = f.first , r = f.second;

        if( l > r || l < 1 || r > n ) continue;

        //cout << "Range : " << l << " " << r << endl;
        segment p = Query( 1 , 1 , n , l , r );
        //cout << "Val :  " <<p.val << " " << "ID :  " << p.id <<endl;

        int mxval = p.val , mxid = p.id;
        if( mxid < 1 || mxid > n ) continue;

        if( ara[ mxid ] == h[ mxid ] ) {
           if( l == r ) continue;
           int a = mxid-1 , b = mxid+1;
           Q.push( { l , a } );
           Q.push( { b , r } );
        }
        else {
           Ans ++;
           ara[ mxid ] = mxval;
           GoLeft( mxval , mxid , l );
           GoRight( mxval , mxid , r );
           /*
           printf("After processing : \n");
           for( int i = 1; i <= n; i++ ) printf("%d ",ara[i]);
           printf("\n");
           printf("ANS :  %d\n",Ans);*/

           int a = mxid-1 , b = mxid+1;
           Q.push( { l , a } );
           Q.push( { b , r } );
        }
    }
    printf("%d\n",Ans);
    //printf("Now Array : \n");
    //for( int i = 1; i <= n; i++ ) printf("%d ",ara[i]);
    //printf("\n");
}
int main( int argc , char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&ara[i]);
        for( int i = 1; i <= n; i++ ) scanf("%d",&h[i]);
        bool invalid = false;
        bool done = true;
        for( int i = 1; i <= n; i++ ) {
            if( ara[i] < h[i] ) { invalid = false; break; }
            if( ara[i] != h[i] ) done = false;
        }
        if( invalid ) { printf("-1\n"); continue; }
        if( done ) { printf("0\n"); continue; }

        solve( );
    }
    return 0;
}
