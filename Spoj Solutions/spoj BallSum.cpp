#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

/**
You have a bag filled with N balls.Each Ball has a distinct number from 1 to N
printed on it.All the numbers are distinct. You withdraw two balls from the bag
and take their sum. You need to calculate the probability that the sum is not greater
 than the given number K(<=N). The Answer should be displayed in the form of p/q.
 (except when the answer is 0 or 1)
*/
int main( ) {
        FIO;
        #ifdef OFFLINE
            //freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        LL n , k;
        while( cin >> n >> k ) {
                if( n == -1 && k == -1 ) break;
                LL p = (k+1)/2 - 1;
                LL ans = p*(p+1);
                if( k%2 != 0 ) ans -= ( (k+1)/2 - 1 );
                LL tot = n*(n-1)/2;
                if( ans == 0 ) cout << 0 << endl;
                else if( ans == tot ) cout << 1 << endl;
                else {
                        LL g = __gcd( tot , ans );
                        cout << ans/g << "/" << tot/g << endl;
                }
        }
        return 0;
}






