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

const int Base[] = { 29 , 31 };
const int Mod[] = { 1000000007 , 1000000009 };

string s , t;
int bad[ 30 ];
int k;
set < pair<LL,LL> > S;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> s >> t >> k;
        for( int i = 0; i < t.size(); i++ ) if( t[i] == '0' ) bad[i+1] = 1;
        for( int i = 0; i < s.size(); i++ ) {
                int cnt = 0;
                LL Hash1 = 0 , Hash2 = 0;
                for( int j = i; j < s.size(); j++ ) {
                        if( bad[ s[j]-'a'+1 ] ) cnt++;
                        if( cnt > k ) break;
                        Hash1 = ( Hash1 * Base[0] + s[j] )%Mod[0];
                        Hash2 = ( Hash2 * Base[1] + s[j] )%Mod[1] ;
                        S.insert( {Hash1,Hash2} );
                }
        }
        cout << (int)S.size() << endl;
        return 0;
}





