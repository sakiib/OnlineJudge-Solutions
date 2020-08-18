#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<string>
#include<iomanip>
#include<sstream>
#include<iterator>
#include<set>
#include<map>
#include<list>
using namespace std;
#define ll        long long int
#define llu       unsigned long long
#define dll       long double
#define Fast()    ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(x,y)  __gcd((x),(y))
#define lcm(x,y)  (x)/__gcd((x),(y))*(y)
#define mx3(a,b,c) max(a,max(b,c))
#define mn3(a,b,c) min(a,min(b,c))
#define mxe(a,n)  (*max_element(a,a+n))
#define mne(a,n)  (*min_element(a,a+n))
#define sum(a,n)  (accumulate(a,a+n,0))
#define CLR(a)    memset(a,0,sizeof(a))
#define SET(a)    memset(a,-1,sizeof(a))
#define all(a)    (a.begin(),a.end())
#define rall(a)   (a.rbegin(),a.rend())
#define SQ(x)     ((x)*(x))
#define CU(x)     ((x)*(x)*(x))
#define UB        upper_bound
#define LB        lower_bound
#define pb        push_back
#define X         first
#define Y         second

//----------------------------------------//
const ll INF=1LL*(1e10);//10000000000
const ll MOD=1LL*(1e9+7);//(1000000007)
const int siz=100010;//For smaller array
const double EPS=1e-9;//For Binary search
const double PI=acos(-1.0);
//-----------------------------------------//
inline bool isp(int x) {//Check prime for smaller values
    if(x<2) return false;
    int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {
        if(x%i==0) return false;
    } return true;
}
inline bool leap_year(int x) {
    if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true;
    return false;
}
inline int power(int x,int y) {//For Smaller values
    int ret=1;
    for(int i=1;i<=y;i++) {
        ret*=x;
    }  return ret;
}
inline int st_int(string &str) {//For smaller values
    int num;
    stringstream st(str); st>>num; return num;
}
inline string int_st(int num) {//For smaller values
    string res; stringstream convert;
    convert<<num; res=convert.str(); return res;
}
//------------------------------------------//
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
    /*for(ll i=2;i<10000000;i++){
        if(isprime[i]) prime.push_back(i);
    }*/
}
//-----------------------------------------//
//----------------------------------------//

int main(int argc,char const *argv[]) {
    Fast();
    sieve();
    int n;
    cin>>n;
    for(int i=4;;i++) {
        if(!isprime[i]&&!isprime[n-i]) {
            cout<<i<< " " <<n-i<<endl;
            return 0;
        }
    }
    return 0;
}

