#include <bits/stdc++.h>

using namespace std;

#define All(x) x.begin(),x.end()
#define error(args...) {string _s = #args; replace( All(_s), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err( istream_iterator <string> it ) {}
template < typename T , typename... Args >
void err( istream_iterator <string> it , T a , Args... args ) { cerr << *it << " = " << a << " ,  "; err(++it, args...); cout << endl; }


int main() {
	int temp = 4, sum = 8, tot = 9;
	error(temp, sum, tot);
	error(temp, sum, tot);
	error(temp, sum, tot);
    vector <int> V = { 1 , 2 , 3 };
    for( int i = 0; i < V.size(); i++ ) error( i , V[i] );
	return 0;
}
