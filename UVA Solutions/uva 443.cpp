#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MX = 2000000000;
set< LL > S;
vector< LL > V;
LL Two[ 100 ] , Three[ 100 ] , Five[ 100 ] , Seven[ 100 ];

void calc() {

    Two[0] = Three[0] = Five[0] = Seven[0] = 1LL;
    S.insert( 1 );
    for( LL i = 1; i <= 62; i++ ) {
        Two[i] = Two[i-1]*2;
        if( Two[i] > MX ) break;
        S.insert( Two[i] );
    }
    for( LL i = 1; i <= 40; i++ ) {
        Three[i] = Three[i-1]*3;
        if( Three[i] > MX ) break;
        S.insert( Three[i] );
    }
    for( LL i = 1; i <= 40; i++ ) {
        Five[i] = Five[i-1]*5;
        if( Five[i] > MX ) break;
        S.insert( Five[i] );
    }
    for( LL i = 1; i <= 40; i++ ) {
        Seven[i] = Seven[i-1]*7;
        if( Seven[i] > MX ) break;
        S.insert( Seven[i] );
    }
    for( int i = 0; i <= 60; i++ ) {
        for( int j = 0; j <= 40; j++ ) {
            for( int k = 0; k <= 40; k++ ) {
                for( int l = 0; l <= 40; l++ ) {
                    LL val = Two[i]*Three[j]*Five[k]*Seven[l];
                    if( val > 0 && val <= MX ) S.insert( val );
                    else break;
                }
            }
        }
    }
    for( auto x : S ) V.push_back( x );
}
string get_ans(LL n) {
    if(n%10==1&&(n%100)/10!=1) return "st";
    if(n%10==2&&(n%100)/10!=1) return "nd";
    if(n%10==3&&(n%100)/10!=1) return "rd";
    else return "th";
}
int main(int argc,char const *argv[]) {
    LL n;
    calc();
    while(scanf("%lld",&n)) {
        if(n==0) break;
        string text=get_ans(n);
        printf("The %lld",n);
        cout<<text<<" ";
        printf("humble number is %lld.\n",V[n-1]);
    }
    return 0;
}
