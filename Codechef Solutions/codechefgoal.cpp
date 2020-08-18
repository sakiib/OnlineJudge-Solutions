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

int main( int argc, char const *argv[] ) {
    string s;
   	while( cin >> s ) {
		int A = 0 , B = 0 , pos = -1 , totA = 5 , totB = 5;
		for ( int i = 0; i < 10; i++ ){
			if( i%2 == 0 && s[i] == '1' ) A++;
			else if( i%2 != 0 && s[i] == '1' ) B++;
			if( i%2 == 0 ) totA--;
			else totB--;
			if( A > B && ((A-B ) > totB) ) {
				pos = i+1;
				break;
			}
			else if( B > A && ((B-A) > totA) ) {
				pos = i+1;
				break;
			}
		}
		if( A == B ) {
			for ( int i = 10; i < 20; i++ ) {
				if( i%2 == 0 && s[i] == '1' ) A++;
				else if( i%2 != 0 && s[i] == '1' ) B++;
				if( A != B && i%2 != 0 ) {
					pos = i+1;
					break;
				}
			}
		}
		if( A > B ) printf("TEAM-A %d\n",pos);
		else if( A < B ) printf("TEAM-B %d\n",pos);
		else printf("TIE\n");
	}
	return 0;
}

