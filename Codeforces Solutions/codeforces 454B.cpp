#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define ll          long long int
#define llu         unsigned long long int
#define dll         long double
#define gcd(x,y)    __gcd((x),(y))
#define lcm(x,y)    (x)/__gcd((x),(y))*(y)
#define mx3(a,b,c)   max(a,max(b,c))
#define mn3(a,b,c)   min(a,min(b,c))
#define mxe(a,n)    (*max_element(a,a+n))
#define mne(a,n)    (*min_element(a,a+n))
#define sum(a,n)    (accumulate(a,a+n,0))
#define CLR(a)       memset(a,0,sizeof(a))
#define SET(a)       memset(a,-1,sizeof(a))
#define all(a)      (a.begin(),a.end())
#define rall(a)     (a.rbegin(),a.rend())
#define SQ(x)       ((x)*(x))
#define CU(x)       ((x)*(x)*(x))
#define UB          upper_bound
#define LB          lower_bound
#define PB          push_back
#define X           first
#define Y           second
#define endl        '\n'
#define dis(x1,y1,x2,y2) sqrt(SQ(x1-x2)+SQ(y1-y2))
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL)
//-------------------------------------------------------//
//------------------------------------------------------//
const ll INF = 1LL*(1e10);
const ll MOD = 1LL*(1e9+7);
const int Size = 100010;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double PII = 2*acos(0.0);
//-------------------------------------------------------//
inline bool isp(int x) {
    if(x<2) return false;
    int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {
        if(x%i==0) return false;
    } return true;
}
//--------------------------------------------------------//
inline bool leap_year(int x) {
    if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true;
    return false;
}
//--------------------------------------------------------//
inline int power(int x,int y) {
    int ret=1;
    for(int i=1;i<=y;i++) {
        ret*=x;
    }  return ret;
}
//--------------------------------------------------------//
inline int st_int(string &str) {
    int num;
    stringstream st(str); st>>num; return num;
}
//--------------------------------------------------------//
inline string int_st(int num) {
    string res; stringstream convert;
    convert<<num; res=convert.str(); return res;
}
//--------------------------------------------------------//
vector<ll> prime;
vector<bool> isprime(1000000,true);
inline void sieve(){

    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;
    for(ll i=2;i<=sqrt(1000000);i++){
        if(isprime[i]){
            for(ll j=i;j*i<1000000;j++){
            isprime[i*j]=false;
            }
        }
    }
    for(ll i=2;i<=1000000;i++){
        if(isprime[i]) prime.push_back(i);
    }
}
//----------------------------------------------------------//
//---------------------------------------------------------//

int main(int argc,char const *argv[]) {
    Fast;
    int n;
    cin>>n;
    int ara[100010];
    map<int,int> M;
    int mn=1000010;
    int pos,cnt=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    for(int i=1;i<n;i++) {
        if(ara[i]>ara[i+1]) {
            cnt++;
            pos=i;
        }
    }
    if(cnt==0) {
        cout<<0<<endl; return 0;
    }
    if(cnt==1&&ara[1]>=ara[n]) cout<<n-pos<<endl;
    else cout<<-1<<endl;
    return 0;
}


