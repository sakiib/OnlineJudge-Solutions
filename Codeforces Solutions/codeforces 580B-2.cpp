#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector <pair<LL,LL> > V;

int main( int argc, char const *argv[] ) {
    LL n, d;
    scanf("%lld%lld",&n,&d);
    for ( int i = 1; i <= n; i++ ){
       LL mon, fact;
       scanf("%lld%lld",&mon,&fact);
       V.push_back( {mon,fact} );
    }
    sort( V.begin(), V.end() );
    LL sum = 0, ans = 0;
    int j = 0;
    for ( int i = 0; i < V.size();  ) {
        if ( V[i].first - V[j].first < d ){
            sum += V[i].second;
            i++;
        }
        else {
            sum -= V[j].second;
            j++;
        }
        ans = max( ans , sum );
    }
    printf("%lld\n",ans);
    return 0;
}
