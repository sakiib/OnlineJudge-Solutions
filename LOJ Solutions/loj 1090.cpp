#include <bits/stdc++.h>
using namespace std;

int Fact( int num , int key ) {
        int ret = 0;
        while( num ) num /= key , ret += num;
        return ret;
}
int Num( int num , int key ) {
        int ret = 0;
        while( num%key == 0 ) num /= key , ret++;
        return ret;
}
int main( int argc, char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , r , p , q;
                scanf("%d %d %d %d",&n,&r,&p,&q);
                int k = n - r;
                int F_nFact = Fact( n , 5 ) , T_nFact = Fact( n , 2 );
                int F_pNum = q * Num( p , 5 ) , T_pNum = q * Num( p , 2 );
                int F_rFact = Fact( r , 5 ) , T_rFact = Fact( r , 2 );
                int F_kFact = Fact( k , 5 ) , T_kFact = Fact( k , 2 );
                int upF = F_nFact + F_pNum , upT = T_nFact + T_pNum;
                int downF = F_rFact + F_kFact , downT = T_rFact + T_kFact;
                int F_rem = upF - downF , T_rem = upT - downT;
                int ans = min( F_rem , T_rem );
                printf("Case %d: %d\n",tc,ans);
        }
        return 0;
}

