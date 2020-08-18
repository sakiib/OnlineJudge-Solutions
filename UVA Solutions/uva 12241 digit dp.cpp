#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int a , b;
LL ans[ 10 ];
LL dp[11][2][11][10][2];
int len;
vector <int> V;

LL go( int idx , int chk , int cnt , int dig , int st , int k ) {
        cout <<"here : "<< idx << " " << cnt << " " << st << " "<< k << endl;
        if(idx >= len ) {
                cout <<endl;
                return cnt;
        }
        if( dp[idx][chk][cnt][dig][st] != -1 ) return dp[idx][chk][cnt][dig][st];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                        ret += go( idx + 1 , 1 , cnt + ( st == 0 && (i == dig) )?1:0  , dig , ( st && ( i == 0 ) ) , i );
                }
        }
        else {
                for( int i = 0; i < V[idx]; i++ ) {
                        ret += go( idx + 1 , 1 ,  cnt + ( st == 0 && (i == dig) )?1:0 , dig , (st && (i == 0) ), i );
                }
                ret += go( idx + 1 , 0 , cnt + ( st == 0 && (V[idx] == dig) )?1:0 , dig , ( st && ( V[idx] == 0 ) ) , V[idx] );
        }
        return dp[idx][chk][cnt][dig][st] = ret;
}
LL solve( int num , int d ) {
        V.clear();
        memset( dp , -1 , sizeof( dp ) );
        //if( num <= 0 ) return num <= d;
        if( num < 10 ) return d <= num;
        while( num ) V.push_back( num%10 ) , num /= 10;
        reverse( V.begin() , V.end() );
        len = V.size();
        cout<< "ken"<<" "<<len <<endl;
        return go( 0 , 0 , 0 , d , 1 ,-1 );
}
int main( int argc , char const *argv[] ) {
        //ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> a >> b ) {
                memset( ans , 0 , sizeof( ans ) );
                for( int i = 0; i <= 9; i++ ) {
                        cout <<"FOR : " << i << endl;
                        ans[i] = solve( b , i );
                        //cout << i << " "<< ans[i]<<endl;
                        ans[i] -= solve( a - 1 , i );
                        //cout << i << " " <<ans[i]<<endl;
                }
                for( int i = 0; i <= 9; i++ ) {
                        if( i == 0 ) cout << ans[i];
                        else cout << " " << ans[i];
                }
                cout << endl;
        }
        return 0;
}










